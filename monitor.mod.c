#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xb06a91bd, "cdev_init" },
	{ 0x7db91808, "cdev_add" },
	{ 0x02f9bbf0, "init_timer_key" },
	{ 0x058c185a, "jiffies" },
	{ 0x32feeafc, "mod_timer" },
	{ 0xe8213e80, "_printk" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xfbc10eaa, "class_destroy" },
	{ 0x0bc5fb0d, "unregister_chrdev_region" },
	{ 0x88b4fdc1, "device_destroy" },
	{ 0x2352b148, "timer_delete_sync" },
	{ 0xde338d9a, "_raw_spin_lock" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0xde338d9a, "_raw_spin_unlock" },
	{ 0x6ce3748e, "cdev_del" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0xc2fefbb5, "kmalloc_caches" },
	{ 0x38395bf3, "__kmalloc_cache_noprof" },
	{ 0xc609ff70, "strncpy" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0x98ba4f31, "mmput" },
	{ 0xd272d446, "__rcu_read_lock" },
	{ 0xe0bcbe51, "find_vpid" },
	{ 0xcf295943, "pid_task" },
	{ 0xd272d446, "__rcu_read_unlock" },
	{ 0xf3a689eb, "get_task_mm" },
	{ 0x465d094f, "__put_task_struct" },
	{ 0x2520ea93, "refcount_warn_saturate" },
	{ 0xce88f9a5, "send_sig" },
	{ 0xe4de56b4, "__ubsan_handle_load_invalid_value" },
	{ 0xd272d446, "__fentry__" },
	{ 0x9f222e1e, "alloc_chrdev_region" },
	{ 0x3d568d84, "class_create" },
	{ 0xa2e1228b, "device_create" },
	{ 0x70eca2ca, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xb06a91bd,
	0x7db91808,
	0x02f9bbf0,
	0x058c185a,
	0x32feeafc,
	0xe8213e80,
	0xd272d446,
	0xfbc10eaa,
	0x0bc5fb0d,
	0x88b4fdc1,
	0x2352b148,
	0xde338d9a,
	0xcb8b6ec6,
	0xde338d9a,
	0x6ce3748e,
	0x092a35a2,
	0xbd03ed67,
	0xc2fefbb5,
	0x38395bf3,
	0xc609ff70,
	0xd272d446,
	0x98ba4f31,
	0xd272d446,
	0xe0bcbe51,
	0xcf295943,
	0xd272d446,
	0xf3a689eb,
	0x465d094f,
	0x2520ea93,
	0xce88f9a5,
	0xe4de56b4,
	0xd272d446,
	0x9f222e1e,
	0x3d568d84,
	0xa2e1228b,
	0x70eca2ca,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"cdev_init\0"
	"cdev_add\0"
	"init_timer_key\0"
	"jiffies\0"
	"mod_timer\0"
	"_printk\0"
	"__x86_return_thunk\0"
	"class_destroy\0"
	"unregister_chrdev_region\0"
	"device_destroy\0"
	"timer_delete_sync\0"
	"_raw_spin_lock\0"
	"kfree\0"
	"_raw_spin_unlock\0"
	"cdev_del\0"
	"_copy_from_user\0"
	"random_kmalloc_seed\0"
	"kmalloc_caches\0"
	"__kmalloc_cache_noprof\0"
	"strncpy\0"
	"__stack_chk_fail\0"
	"mmput\0"
	"__rcu_read_lock\0"
	"find_vpid\0"
	"pid_task\0"
	"__rcu_read_unlock\0"
	"get_task_mm\0"
	"__put_task_struct\0"
	"refcount_warn_saturate\0"
	"send_sig\0"
	"__ubsan_handle_load_invalid_value\0"
	"__fentry__\0"
	"alloc_chrdev_region\0"
	"class_create\0"
	"device_create\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "04861BABEF506226C464E1D");
