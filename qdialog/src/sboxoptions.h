/****************************************************************************
 **
 ** Copyright (C) 2009 Evgeniy V. Sergeev.  All rights reserved.
 **
 ** This file may be used under the terms of the GNU General Public
 ** License version 2.0 as published by the Free Software Foundation
 ** and appearing in the file LICENSE.GPL included in the packaging of
 ** this file.  Please review the following information to ensure GNU
 ** General Public Licensing requirements will be met:
 ** http://www.trolltech.com/products/qt/opensource.html
 **
 ** If you are unsure which license is appropriate for your use, please
 ** review the following information:
 ** http://www.trolltech.com/products/qt/licensing.html or contact the
 ** sales department at sales@trolltech.com.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ** AUTHOR: Evgeniy V. Sergeev <evgeniy.sergeev@gmail.com>
 **
 ****************************************************************************/
#ifndef __SBOXOPTIONS_H__
#define __SBOXOPTIONS_H__

struct SBoxOptions
{
public:
    SBoxOptions()
    {
        erase();
    }

    void erase()
    {
        //and_widget         = false; // ignore
        beep_after_signal  = false;
        beep_signal        = false;
        begin_set          = false;
        //cant_kill          = false; // ignore
        colors             = false;
        cr_wrap            = false;
        defaultno          = false;
        //clear              = false; // ignore
        extra_button       = false;
        help_button        = false;
        no_ok              = false;
        no_cancel          = false;
        help_status        = false;
        input_menu         = false;
        insecure           = false;
        item_help          = false;
        keep_window        = false;
        nocollapse         = false;
        notags             = false;
        print_size         = false;
        separate_output    = false;
        single_quoted      = false;
        size_err           = false;
        tab_correct        = false;
        trim_whitespace    = false;
        size_in_pixels     = false;
        size_set           = false;
        height             = 0;
        width              = 0;
        begin_x            = 0;
        begin_y            = 0;
        max_input          = 0;
        scale_factor       = 0;
        sleep_secs         = 0;
        timeout_secs       = 0;
        input_length       = 0;
        cancel_label       = "";
        default_item       = "";
        exit_label         = "";
        extra_label        = "";
        help_label         = "";
        no_label           = "";
        ok_label           = "";
        title              = "";
        yes_label          = "";
    }
/*    CBox(const CBox& aBox)
    {
        and_widget         = aBox.and_widhet;
        beep_after_signal  = beep_after_signal;
        beep_signal        = beep_signal;
        begin_set          = begin_set;
        cant_kill          = cant_kill;
        colors             = colors;
        cr_wrap            = cr_wrap;
        defaultno          = defaultno;
        clear              = clear;
        extra_button       = extra_button;
        help_button        = help_button;
        help_status        = help_status;
        input_menu         = input_menu;
        insecure           = insecure;
        item_help          = item_help;
        keep_window        = false;
        nocancel           = false;
        nocollapse         = false;
        print_size         = false;
        separate_output    = false;
        single_quoted      = false;
        size_err           = false;
        tab_correct        = false;
        trim_whitespace    = false;
        begin_x            = 0;
        begin_y            = 0;
        max_input          = 0;
        scale_factor       = 0;
        sleep_secs         = 0;
        timeout_secs       = 0;
        input_length       = 0;

    }
*/
public:
    bool    and_widget;             // option "--and-widget"
    bool    beep_after_signal;      // option "--beep-after"
    bool    beep_signal;            // option "--beep"
    bool    begin_set;              // option "--begin y x" was used
    bool    cant_kill;              // option "--no-kill"
    bool    colors;                 // option "--colors"
    bool    cr_wrap;                // option "--cr-wrap"
    bool    defaultno;              // option "--defaultno"
    bool    clear;                  // option "--clear"
    bool    extra_button;           // option "--extra-button"
    bool    help_button;            // option "--help-button"
    bool    help_status;            // option "--help-status"
    bool    input_menu;             // menu vs inputmenu widget
    bool    insecure;               // option "--insecure"
    bool    item_help;              // option "--item-help"
    bool    keep_window;            // option "--keep-window"
    bool    no_cancel;              // option "--no-cancel"
    bool    no_ok;                  // option "--no-ok"
    bool    nocollapse;             // option "--no-collapse"
    bool    notags;                 // option "--no-tags"
    bool    print_size;             // option "--print-size"
    bool    separate_output;        // option "--separate-output"
    bool    single_quoted;          // option "--single-quoted"
    bool    size_err;               // option "--size-err"
    bool    tab_correct;            // option "--tab-correct"
    bool    trim_whitespace;        // option "--trim"
    bool    size_in_pixels;         // 
    bool    size_set;               // 
    QString cancel_label;   // option "--cancel-label string"
    QString default_item;   // option "--default-item string"
    QString exit_label;     // option "--exit-label string"
    QString extra_label;    // option "--extra-label string"
    QString help_label;     // option "--help-label string"
    QString no_label;       // option "--no-label string"
    QString ok_label;       // option "--ok-label string"
    QString title;          // option "--title title"
    QString yes_label;      // option "--yes-label string"
    int     begin_x;                // option "--begin y x" (second value)
    int     begin_y;                // option "--begin y x" (first value)
    long    height;
    long    width;
    int     max_input;              // option "--max-input size"
    int     scale_factor;           // RESERVED
    int     sleep_secs;             // option "--sleep secs"
    int     timeout_secs;           // option "--timeout secs"
    int     aspect;                 // option "--aspect-ratio"
    unsigned input_length;          // nonzero if input_result is allocated
};

#endif // __SBOXOPTIONS_H
