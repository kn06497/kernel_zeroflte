/*
 *
 * (C) COPYRIGHT ARM Limited. All rights reserved.
 *
 * This program is free software and is provided to you under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation, and any use by you of this program is subject to the terms
 * of such GNU licence.
 *
 * A copy of the licence is included with the program, and can also be obtained
 * from Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 *
 */




#if !defined(_TRACE_MALI_KBASE_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_MALI_KBASE_H

#undef TRACE_SYSTEM
#define TRACE_SYSTEM mali

#include <linux/tracepoint.h>

DECLARE_EVENT_CLASS(mali_slot_template,
	TP_PROTO(int jobslot, unsigned int info_val),
	TP_ARGS(jobslot, info_val),
	TP_STRUCT__entry(
		__field(unsigned int, jobslot)
		__field(unsigned int, info_val)
	),
	TP_fast_assign(
		__entry->jobslot = jobslot;
		__entry->info_val = info_val;
	),
	TP_printk("jobslot=%u info=%u", __entry->jobslot, __entry->info_val)
);

#define DEFINE_MALI_SLOT_EVENT(name) \
DEFINE_EVENT(mali_slot_template, mali_##name, \
	TP_PROTO(int jobslot, unsigned int info_val), \
	TP_ARGS(jobslot, info_val))
DEFINE_MALI_SLOT_EVENT(JM_SUBMIT);
DEFINE_MALI_SLOT_EVENT(JM_JOB_DONE);
DEFINE_MALI_SLOT_EVENT(JM_UPDATE_HEAD);
DEFINE_MALI_SLOT_EVENT(JM_CHECK_HEAD);
DEFINE_MALI_SLOT_EVENT(JM_SOFTSTOP);
DEFINE_MALI_SLOT_EVENT(JM_SOFTSTOP_0);
DEFINE_MALI_SLOT_EVENT(JM_SOFTSTOP_1);
DEFINE_MALI_SLOT_EVENT(JM_HARDSTOP);
DEFINE_MALI_SLOT_EVENT(JM_HARDSTOP_0);
DEFINE_MALI_SLOT_EVENT(JM_HARDSTOP_1);
DEFINE_MALI_SLOT_EVENT(JM_SLOT_SOFT_OR_HARD_STOP);
DEFINE_MALI_SLOT_EVENT(JM_SLOT_EVICT);
DEFINE_MALI_SLOT_EVENT(JM_BEGIN_RESET_WORKER);
DEFINE_MALI_SLOT_EVENT(JM_END_RESET_WORKER);
DEFINE_MALI_SLOT_EVENT(JS_CORE_REF_REGISTER_ON_RECHECK_FAILED);
DEFINE_MALI_SLOT_EVENT(JS_AFFINITY_SUBMIT_TO_BLOCKED);
DEFINE_MALI_SLOT_EVENT(JS_AFFINITY_CURRENT);
DEFINE_MALI_SLOT_EVENT(JD_DONE_TRY_RUN_NEXT_JOB);
DEFINE_MALI_SLOT_EVENT(JS_CORE_REF_REQUEST_CORES_FAILED);
DEFINE_MALI_SLOT_EVENT(JS_CORE_REF_REGISTER_INUSE_FAILED);
DEFINE_MALI_SLOT_EVENT(JS_CORE_REF_REQUEST_ON_RECHECK_FAILED);
DEFINE_MALI_SLOT_EVENT(JS_CORE_REF_AFFINITY_WOULD_VIOLATE);
DEFINE_MALI_SLOT_EVENT(JS_JOB_DONE_TRY_RUN_NEXT_JOB);
DEFINE_MALI_SLOT_EVENT(JS_JOB_DONE_RETRY_NEEDED);
DEFINE_MALI_SLOT_EVENT(JS_POLICY_DEQUEUE_JOB);
DEFINE_MALI_SLOT_EVENT(JS_POLICY_DEQUEUE_JOB_IRQ);
#undef DEFINE_MALI_SLOT_EVENT

DECLARE_EVENT_CLASS(mali_refcount_template,
	TP_PROTO(int refcount, unsigned int info_val),
	TP_ARGS(refcount, info_val),
	TP_STRUCT__entry(
		__field(unsigned int, refcount)
		__field(unsigned int, info_val)
	),
	TP_fast_assign(
		__entry->refcount = refcount;
		__entry->info_val = info_val;
	),
	TP_printk("refcount=%u info=%u", __entry->refcount, __entry->info_val)
);

#define DEFINE_MALI_REFCOUNT_EVENT(name) \
DEFINE_EVENT(mali_refcount_template, mali_##name, \
	TP_PROTO(int refcount, unsigned int info_val), \
	TP_ARGS(refcount, info_val))
DEFINE_MALI_REFCOUNT_EVENT(JS_RETAIN_CTX_NOLOCK);
DEFINE_MALI_REFCOUNT_EVENT(JS_ADD_JOB);
DEFINE_MALI_REFCOUNT_EVENT(JS_REMOVE_JOB);
DEFINE_MALI_REFCOUNT_EVENT(JS_RETAIN_CTX);
DEFINE_MALI_REFCOUNT_EVENT(JS_RELEASE_CTX);
DEFINE_MALI_REFCOUNT_EVENT(JS_TRY_SCHEDULE_HEAD_CTX);
DEFINE_MALI_REFCOUNT_EVENT(JS_POLICY_INIT_CTX);
DEFINE_MALI_REFCOUNT_EVENT(JS_POLICY_TERM_CTX);
DEFINE_MALI_REFCOUNT_EVENT(JS_POLICY_ENQUEUE_CTX);
DEFINE_MALI_REFCOUNT_EVENT(JS_POLICY_DEQUEUE_HEAD_CTX);
DEFINE_MALI_REFCOUNT_EVENT(JS_POLICY_TRY_EVICT_CTX);
DEFINE_MALI_REFCOUNT_EVENT(JS_POLICY_RUNPOOL_ADD_CTX);
DEFINE_MALI_REFCOUNT_EVENT(JS_POLICY_RUNPOOL_REMOVE_CTX);
DEFINE_MALI_REFCOUNT_EVENT(JS_POLICY_FOREACH_CTX_JOBS);
DEFINE_MALI_REFCOUNT_EVENT(PM_CONTEXT_ACTIVE);
DEFINE_MALI_REFCOUNT_EVENT(PM_CONTEXT_IDLE);
#undef DEFINE_MALI_REFCOUNT_EVENT

DECLARE_EVENT_CLASS(mali_add_template,
	TP_PROTO(int gpu_addr, unsigned int info_val),
	TP_ARGS(gpu_addr, info_val),
	TP_STRUCT__entry(
		__field(unsigned int, gpu_addr)
		__field(unsigned int, info_val)
	),
	TP_fast_assign(
		__entry->gpu_addr = gpu_addr;
		__entry->info_val = info_val;
	),
	TP_printk("gpu_addr=%u info=%u", __entry->gpu_addr, __entry->info_val)
);

#define DEFINE_MALI_ADD_EVENT(name) \
DEFINE_EVENT(mali_add_template, mali_##name, \
	TP_PROTO(int gpu_addr, unsigned int info_val), \
	TP_ARGS(gpu_addr, info_val))
DEFINE_MALI_ADD_EVENT(CORE_CTX_DESTROY);
DEFINE_MALI_ADD_EVENT(CORE_CTX_HWINSTR_TERM);
DEFINE_MALI_ADD_EVENT(CORE_GPU_IRQ);
DEFINE_MALI_ADD_EVENT(CORE_GPU_IRQ_CLEAR);
DEFINE_MALI_ADD_EVENT(CORE_GPU_IRQ_DONE);
DEFINE_MALI_ADD_EVENT(CORE_GPU_SOFT_RESET);
DEFINE_MALI_ADD_EVENT(CORE_GPU_HARD_RESET);
DEFINE_MALI_ADD_EVENT(CORE_GPU_PRFCNT_SAMPLE);
DEFINE_MALI_ADD_EVENT(CORE_GPU_PRFCNT_CLEAR);
DEFINE_MALI_ADD_EVENT(CORE_GPU_CLEAN_CACHES);
DEFINE_MALI_ADD_EVENT(CORE_GPU_CLEAN_INV_CACHES);
DEFINE_MALI_ADD_EVENT(JD_DONE_WORKER);
DEFINE_MALI_ADD_EVENT(JD_DONE_WORKER_END);
DEFINE_MALI_ADD_EVENT(JD_CANCEL_WORKER);
DEFINE_MALI_ADD_EVENT(JD_DONE);
DEFINE_MALI_ADD_EVENT(JD_CANCEL);
DEFINE_MALI_ADD_EVENT(JD_ZAP_CONTEXT);
DEFINE_MALI_ADD_EVENT(JM_IRQ);
DEFINE_MALI_ADD_EVENT(JM_IRQ_END);
DEFINE_MALI_ADD_EVENT(JM_FLUSH_WORKQS);
DEFINE_MALI_ADD_EVENT(JM_FLUSH_WORKQS_DONE);
DEFINE_MALI_ADD_EVENT(JM_ZAP_NON_SCHEDULED);
DEFINE_MALI_ADD_EVENT(JM_ZAP_SCHEDULED);
DEFINE_MALI_ADD_EVENT(JM_ZAP_DONE);
DEFINE_MALI_ADD_EVENT(JM_SUBMIT_AFTER_RESET);
DEFINE_MALI_ADD_EVENT(JM_JOB_COMPLETE);
DEFINE_MALI_ADD_EVENT(JS_FAST_START_EVICTS_CTX);
DEFINE_MALI_ADD_EVENT(JS_CTX_ATTR_NOW_ON_RUNPOOL);
DEFINE_MALI_ADD_EVENT(JS_CTX_ATTR_NOW_OFF_RUNPOOL);
DEFINE_MALI_ADD_EVENT(JS_CTX_ATTR_NOW_ON_CTX);
DEFINE_MALI_ADD_EVENT(JS_CTX_ATTR_NOW_OFF_CTX);
DEFINE_MALI_ADD_EVENT(JS_POLICY_TIMER_END);
DEFINE_MALI_ADD_EVENT(JS_POLICY_TIMER_START);
DEFINE_MALI_ADD_EVENT(JS_POLICY_ENQUEUE_JOB);
DEFINE_MALI_ADD_EVENT(PM_CORES_CHANGE_DESIRED);
DEFINE_MALI_ADD_EVENT(PM_JOB_SUBMIT_AFTER_POWERING_UP);
DEFINE_MALI_ADD_EVENT(PM_JOB_SUBMIT_AFTER_POWERED_UP);
DEFINE_MALI_ADD_EVENT(PM_PWRON);
DEFINE_MALI_ADD_EVENT(PM_PWRON_TILER);
DEFINE_MALI_ADD_EVENT(PM_PWRON_L2);
DEFINE_MALI_ADD_EVENT(PM_PWROFF);
DEFINE_MALI_ADD_EVENT(PM_PWROFF_TILER);
DEFINE_MALI_ADD_EVENT(PM_PWROFF_L2);
DEFINE_MALI_ADD_EVENT(PM_CORES_POWERED);
DEFINE_MALI_ADD_EVENT(PM_CORES_POWERED_TILER);
DEFINE_MALI_ADD_EVENT(PM_CORES_POWERED_L2);
DEFINE_MALI_ADD_EVENT(PM_DESIRED_REACHED);
DEFINE_MALI_ADD_EVENT(PM_DESIRED_REACHED_TILER);
DEFINE_MALI_ADD_EVENT(PM_UNREQUEST_CHANGE_SHADER_NEEDED);
DEFINE_MALI_ADD_EVENT(PM_REQUEST_CHANGE_SHADER_NEEDED);
DEFINE_MALI_ADD_EVENT(PM_REGISTER_CHANGE_SHADER_NEEDED);
DEFINE_MALI_ADD_EVENT(PM_REGISTER_CHANGE_SHADER_INUSE);
DEFINE_MALI_ADD_EVENT(PM_RELEASE_CHANGE_SHADER_INUSE);
DEFINE_MALI_ADD_EVENT(PM_CORES_AVAILABLE);
DEFINE_MALI_ADD_EVENT(PM_CORES_AVAILABLE_TILER);
DEFINE_MALI_ADD_EVENT(PM_CORES_CHANGE_AVAILABLE);
DEFINE_MALI_ADD_EVENT(PM_CORES_CHANGE_AVAILABLE_TILER);
DEFINE_MALI_ADD_EVENT(PM_GPU_ON);
DEFINE_MALI_ADD_EVENT(PM_GPU_OFF);
DEFINE_MALI_ADD_EVENT(PM_SET_POLICY);
DEFINE_MALI_ADD_EVENT(PM_CURRENT_POLICY_INIT);
DEFINE_MALI_ADD_EVENT(PM_CURRENT_POLICY_TERM);
DEFINE_MALI_ADD_EVENT(PM_CA_SET_POLICY);
DEFINE_MALI_ADD_EVENT(PM_WAKE_WAITERS);
#undef DEFINE_MALI_ADD_EVENT

#endif /* _TRACE_MALI_KBASE_H */

#undef TRACE_INCLUDE_PATH
#undef linux
#define TRACE_INCLUDE_PATH .
#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE mali_linux_kbase_trace

/* This part must be outside protection */
#include <trace/define_trace.h>
