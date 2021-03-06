#ifndef AFL_FUZZ_H
#define AFL_FUZZ_H

// 这里是afl-fuzz.c的一些声明,纯C


#include "types.h"
#include "config.h"
#include "debug.h"

struct queue_entry {

  u8* fname;                          /* File name for the test case      */
  u32 len;                            /* Input length                     */

  u8  cal_failed,                     /* Calibration failed?              */
      trim_done,                      /* Trimmed?                         */
      was_fuzzed,                     /* Had any fuzzing done yet?        */
      passed_det,                     /* Deterministic stages passed?     */
      has_new_cov,                    /* Triggers new coverage?           */
      var_behavior,                   /* Variable behavior?               */
      favored,                        /* Currently favored?               */
      fs_redundant;                   /* Marked as redundant in the fs?   */

  u32 bitmap_size,                    /* Number of bits set in bitmap     */
      exec_cksum;                     /* Checksum of the execution trace  */

  u64 exec_us,                        /* Execution time (us)              */
      handicap,                       /* Number of queue cycles behind    */
      depth;                          /* Path depth                       */

  u8* trace_mini;                     /* Trace bytes, if kept             */
  u32 tc_ref;                         /* Trace bytes ref count            */

  struct queue_entry *next,           /* Next element, if any             */
                     *next_100;       /* 100 elements ahead               */

  u32 id;                             // the id of cur parent
  u8 selected;                        // if selected by our method

};


u8 trim_case(char** argv, struct queue_entry* q, u8* in_buf);

void show_stats(void);



u64 get_cur_time(void);   // 微秒
u64 get_cur_time_us(void);// 毫秒

#endif // end_AFL_FUZZ_H
