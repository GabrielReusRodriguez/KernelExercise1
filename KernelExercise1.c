/*Hello!*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/sched.h>

#define DRIVER_AUTHOR "Gabriel Reus Rodriguez"
#define DRIVER_DESC "Un módulo de prueba para aprender a programar"
#define DRIVER_LICENSE "GPL"
#define TIME_INTERVAL 6000

static int execute(void)
{
	pr_info("ARP Checker executing");
	return 0;
}

static int init(void)
{
	pr_info("Initiating ARP Checker");
	pr_info("ARP Checker initiated");
	/*
	* Marcamos el proceso para que pueda dormir
	*/
	set_current_state(TASK_INTERRUPTIBLE);
	while(1){
		execute();
		pr_info("ARP Checker Executed!");
		schedule_timeout(TIME_INTERVAL);
	}
	return 0;

}

static void cleanup(void)
{

}

module_init(init);
module_exit(cleanup);

MODULE_LICENSE(DRIVER_LICENSE);
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
