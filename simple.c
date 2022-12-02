#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>


struct person {
       int month;
       int day;
       int year;
       struct person *next;
}

struct person *ptr;

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
       
       //create the first node in the list
       ptr = (struct person*) malloc(5 * sizeof(struct person));

       for (int i = 0; i < 4; i++) {
              ptr->day = i;
              ptr->month = i;
              ptr->year = i;
              ptr->next = (ptr+1);
       }

       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

