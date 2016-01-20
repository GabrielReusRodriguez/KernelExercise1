/*Hello!*/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/sched.h>
#include <linux/workqueue.h>

#define DRIVER_AUTHOR "Gabriel Reus Rodriguez"
#define DRIVER_DESC "Un módulo de prueba para aprender a programar"
#define DRIVER_LICENSE "GPL"
#define DRIVER_VERSION "0.1"
#define TIME_INTERVAL 60*HZ

void execute_arp_Checker(void);

static struct workqueue_struct *workq;
static DECLARE_DELAYED_WORK(work,execute_arp_Checker);

void execute_arp_Checker(void)
{
	pr_info("ARP Checker executing\n");
	queue_delayed_work(workq, &work, TIME_INTERVAL);
	//return 0;
}

static int init(void)
{
	pr_info("Initiating ARP Checker\n");
	pr_info("ARP Checker initiated\n");
	/*
	* Marcamos el proceso para que pueda dormir
	*/
	set_current_state(TASK_INTERRUPTIBLE);
	workq = create_singlethread_workqueue("execute_arp_Checker");
  	queue_delayed_work(workq, &work, TIME_INTERVAL);

/*
*	while(1){
*		execute();
*		pr_info("ARP Checker Executed!\n");
*		schedule_timeout(TIME_INTERVAL);
*	}
*/
	return 0;

}

static void cleanup(void)
{
	cancel_delayed_work(&work);
	flush_workqueue(workq);
	destroy_workqueue(workq);
	pr_info(" ARP Checker unloaded\n");
}

module_init(init);
module_exit(cleanup);

MODULE_LICENSE(DRIVER_LICENSE);
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION(DRIVER_VERSION);
