/**
 ******************************************************************************************
 * This file is part of EMF(Effective Multi Microcontroller Framework).
 *
 * @author  Ebrahim Rahmanian (elecstar.ir@gmail.com) (www.elecstar.ir)
 * @brief   Version numbering and version-comparison macros for the EMF framework.
 ******************************************************************************************
 * @attention
 *
 ******************************************************************************************
 * @RELEASE HISTORY
 *
 * DATE                     NAME           DESCRIPTION
 * v5.8_14050505            E.Rahmanian    Create
 ******************************************************************************************
 * @brief Versioning Scheme: Major.Minor.Patch.Attempt
 * 
 * ----------------------------------------------------------------------------
 * ENGLISH (EN):
 * ----------------------------------------------------------------------------
 * Core Logic:
 * - Attempt = 0  -> FINAL, STABLE, production-ready release.
 * - Attempt > 0  -> DEVELOPMENT/TEST build (ongoing attempts to finalize).
 * 
 * Workflow:
 * 1. Start a new change -> Increase the relevant core number (Major/Minor/Patch)
 *    and set Attempt = 1.
 * 2. Each new test build -> Increase only the Attempt number.
 * 3. Finish & Release -> Reset Attempt to 0.
 *  
 * ----------------------------------------------------------------------------
 * فارسی (PERSIAN):
 * ----------------------------------------------------------------------------
 * منطق اصلی:
 * - Attempt = 0  -> نسخه‌ی نهایی، پایدار و آماده‌ی انتشار.
 * - Attempt > 0  -> نسخه‌ی در حال توسعه و تست (تعداد تلاش‌ها برای تکمیل).
 * 
 * روال کاری:
 * 1. شروع تغییر جدید -> شماره‌ی مربوطه (Major/Minor/Patch) را +۱ کرده و 
 *    Attempt را روی ۱ قرار دهید.
 * 2. هر بار ساخت (Build) جدید -> فقط عدد Attempt را افزایش دهید.
 * 3. پایان کار و انتشار -> عدد Attempt را به ۰ برگردانید.
 * 
 * ----------------------------------------------------------------------------
 */

#if defined(EMF_C)
#ifndef EMF_VERSION_H
#define EMF_VERSION_H
 
 
/* ============================================================
 * Version numbers - ONLY change these values
 * Format: Major.Minor.Patch.Attempt
 *
 * شماره نسخه‌ها - فقط این مقادیر را تغییر دهید
 * قالب: اصلی.فرعی.وصله.تلاش
 * ============================================================ */
#define EMF_VERSION_MAJOR     5U
#define EMF_VERSION_MINOR     8U
#define EMF_VERSION_PATCH     0U
#define EMF_VERSION_ATTEMPT   0U
 
 
/* ============================================================
 * API Version (Major.Minor)
 *
 * نسخه API (اصلی.فرعی)
 * ============================================================ */
#define EMF_API_VERSION_MAJOR EMF_VERSION_MAJOR
#define EMF_API_VERSION_MINOR EMF_VERSION_MINOR
 
 
 
/* ============================================================
 * API Version comparison macros  -  ماکروهای مقایسه نسخه API
 *
 * These macros compare only the API version (Major.Minor).
 * No patch or attempt is considered.
 *
 * NOTE: Arguments are evaluated multiple times inside these macros.
 * Pass literals or #define constants only - do NOT pass expressions
 * with side effects (e.g. i++).
 *
 * توجه: پارامترهای ورودی این ماکروها چندین‌بار ارزیابی می‌شوند.
 * فقط مقادیر ثابت یا ماکرو پاس دهید، از عباراتی با side effect
 * (مانند i++) استفاده نکنید.
 * ============================================================ */
 
/* Current API version < given API version */
#define EMF_API_VERSION_IS_LESS(major, minor) \
    ((EMF_API_VERSION_MAJOR <  (major)) || \
     (EMF_API_VERSION_MAJOR == (major) && EMF_API_VERSION_MINOR < (minor)))
 
/* Current API version == given API version */
#define EMF_API_VERSION_IS_EQUAL(major, minor) \
    (EMF_API_VERSION_MAJOR == (major) && EMF_API_VERSION_MINOR == (minor))
 
/* Current API version > given API version */
#define EMF_API_VERSION_IS_GREATER(major, minor) \
    ((EMF_API_VERSION_MAJOR >  (major)) || \
     (EMF_API_VERSION_MAJOR == (major) && EMF_API_VERSION_MINOR > (minor)))
 
/* Current API version >= given API version */
#define EMF_API_VERSION_IS_AT_LEAST(major, minor) \
    (EMF_API_VERSION_IS_GREATER(major, minor) || EMF_API_VERSION_IS_EQUAL(major, minor))
 
/* Current API version <= given API version*/
#define EMF_API_VERSION_IS_AT_MOST(major, minor) \
    (EMF_API_VERSION_IS_LESS(major, minor) || EMF_API_VERSION_IS_EQUAL(major, minor))
 
 
/* ============================================================
 * Full version comparison macros  -  ماکروهای مقایسه نسخه کامل
 *
 * Compare Major.Minor.Patch.Attempt
 *
 * NOTE: Arguments are evaluated multiple times inside these macros.
 * Pass literals or #define constants only - do NOT pass expressions
 * with side effects (e.g. i++).
 *
 * توجه: پارامترهای ورودی این ماکروها چندین‌بار ارزیابی می‌شوند.
 * فقط مقادیر ثابت یا ماکرو پاس دهید، از عباراتی با side effect
 * (مانند i++) استفاده نکنید.
 * ============================================================ */
 
/* Current full version < given full version */
#define EMF_VERSION_IS_LESS(major, minor, patch, attempt) \
    ((EMF_VERSION_MAJOR <  (major)) || \
     (EMF_VERSION_MAJOR == (major) && EMF_VERSION_MINOR <  (minor)) || \
     (EMF_VERSION_MAJOR == (major) && EMF_VERSION_MINOR == (minor) && EMF_VERSION_PATCH < (patch)) || \
     (EMF_VERSION_MAJOR == (major) && EMF_VERSION_MINOR == (minor) && EMF_VERSION_PATCH == (patch) && EMF_VERSION_ATTEMPT < (attempt)))
 
/* Current full version == given full version*/
#define EMF_VERSION_IS_EQUAL(major, minor, patch, attempt) \
    (EMF_VERSION_MAJOR == (major) && \
     EMF_VERSION_MINOR == (minor) && \
     EMF_VERSION_PATCH == (patch) && \
     EMF_VERSION_ATTEMPT == (attempt))
 
/* Current full version > given full version */
#define EMF_VERSION_IS_GREATER(major, minor, patch, attempt) \
    ((EMF_VERSION_MAJOR >  (major)) || \
     (EMF_VERSION_MAJOR == (major) && EMF_VERSION_MINOR >  (minor)) || \
     (EMF_VERSION_MAJOR == (major) && EMF_VERSION_MINOR == (minor) && EMF_VERSION_PATCH > (patch)) || \
     (EMF_VERSION_MAJOR == (major) && EMF_VERSION_MINOR == (minor) && EMF_VERSION_PATCH == (patch) && EMF_VERSION_ATTEMPT > (attempt)))
 
/* Current full version >= given full version */
#define EMF_VERSION_IS_AT_LEAST(major, minor, patch, attempt) \
    (EMF_VERSION_IS_GREATER(major, minor, patch, attempt) || \
     EMF_VERSION_IS_EQUAL(major, minor, patch, attempt))
 
/* Current full version <= given full version */
#define EMF_VERSION_IS_AT_MOST(major, minor, patch, attempt) \
    (EMF_VERSION_IS_LESS(major, minor, patch, attempt) || \
     EMF_VERSION_IS_EQUAL(major, minor, patch, attempt))
 
#endif
#endif