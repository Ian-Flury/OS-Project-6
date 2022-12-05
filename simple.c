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
};

struct person *ptr1;
struct person *ptr2;
struct person *ptr3;
struct person *ptr4;
struct person *ptr5;

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
       
       //create the first node in the list
       ptr1 = kmalloc(sizeof(struct person), GFP_KERNEL);
       ptr2 = kmalloc(sizeof(struct person), GFP_KERNEL);
       ptr3 = kmalloc(sizeof(struct person), GFP_KERNEL);
       ptr4 = kmalloc(sizeof(struct person), GFP_KERNEL);
       ptr5 = kmalloc(sizeof(struct person), GFP_KERNEL);

       ptr1->month = 1;
       ptr1->day = 1;
       ptr1->year = 1;
       ptr1->next = ptr2;

       ptr2->month = 2;
       ptr2->day = 2;
       ptr2->year = 2;
       ptr2->next = ptr3;

       ptr3->month = 3;
       ptr3->day = 3;
       ptr3->year = 3;
       ptr3->next = ptr4;
       
       ptr4->month = 4;
       ptr4->day = 4;
       ptr4->year = 4;
       ptr4->next = ptr5;
       
       ptr5->month = 5;
       ptr5->day = 5;
       ptr5->year = 5;
       ptr5->next = NULL;

       //print the list:

       struct person *traverPtr = ptr1;
       while (traverPtr != NULL) {
              printk("Month: %d, Day: %d Year: %d", traverPtr->month, traverPtr->day, traverPtr->year);
              traverPtr = traverPtr->next;
       }
       printk("done printing...\n");

       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
       
       kfree(ptr5);
       
       ptr4->next = NULL;
       kfree(ptr4);

       ptr3->next = NULL;
       kfree(ptr3);

       ptr2->next = NULL;
       kfree(ptr2);

       ptr1->next = NULL;
       kfree(ptr1);
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

