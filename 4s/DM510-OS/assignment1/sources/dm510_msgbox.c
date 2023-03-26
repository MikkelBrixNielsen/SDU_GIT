#include "linux/kernel.h"
#include "linux/unistd.h"
#include "linux/slab.h"
#include "linux/uaccess.h"

typedef struct _msg_t msg_t;

struct _msg_t {
	msg_t* previous;
	int length;
	char* message;
};

static msg_t *bottom = NULL;
static msg_t *top = NULL;

asmlinkage
int sys_dm510_msgbox_put( char *buffer, int length ) {
	msg_t* msg;
	unsigned long flags;
	if (!buffer || length < 0) { return -EINVAL; }
	msg = kmalloc(sizeof(msg_t), GFP_KERNEL);
	if (msg == NULL) { return -EADDRNOTAVAIL; }
	msg->previous = NULL;
	msg->length = length;
	msg->message = kmalloc(length, GFP_KERNEL);
	if (msg->message == NULL) { return -EADDRNOTAVAIL; }
	local_irq_save(flags);
	if (!(access_ok(buffer, length)) || copy_from_user(msg->message, buffer, length) != 0) {
		local_irq_restore(flags);
		return -EFAULT;
	}
	if (bottom == NULL) {
		bottom = msg;
		top = msg;
	} else {
		msg->previous = top;
		top = msg;
	}
	local_irq_restore(flags);
	return 0;
}

asmlinkage
int sys_dm510_msgbox_get( char* buffer, int length ) {
	msg_t* msg;
	int mlength;
	unsigned long flags;
	if (!buffer || length < 0) { return -EINVAL; }
	if (top != NULL) {
		local_irq_save(flags);
		msg = top;
		mlength = msg->length;
		if (msg->length > length) { return -EMSGSIZE; } 
		if (!(access_ok(buffer, mlength)) || copy_to_user(buffer, msg->message, mlength) != 0) {
			local_irq_restore(flags);
			return -EFAULT;
		}
		top = msg->previous;
		kfree(msg->message);
		kfree(msg);
		local_irq_restore(flags);
		return mlength;
	}
	return -ENODATA;
}
