/* * This file is part of meego-im-framework *
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 * Contact: Nokia Corporation (directui@nokia.com)
 *
 * If you have questions regarding the use of this file, please contact
 * Nokia at directui@nokia.com.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * and appearing in the file LICENSE.LGPL included in the packaging
 * of this file.
 */

#ifndef MINPUTMETHODNAMESPACE_H
#define MINPUTMETHODNAMESPACE_H

#include <QMetaType>
#include <QSharedPointer>

/* This namespace is deprecated. The Maliit:: namespace is the new equivalent.
 * New interfaces should use Maliit instead. */

namespace MInputMethod {

    /*!
     * This enum contains values of the orientation angle of windows in the application.
     *
     * \sa Orientation
     */
    enum OrientationAngle {
        Angle0   =   0,
        Angle90  =  90,
        Angle180 = 180,
        Angle270 = 270
    };

    /*!
     * This enum contains possible values for orientation of windows in the application.
     *
     * \sa OrientationAngle
     */
    enum Orientation {
        Portrait, //!< equal to either M::Angle90 or M::Angle270 orientation angles
        Landscape //!< equal to either M::Angle0 or M::Angle180 orientation angles
    };

    //! Content type for text entries. Used at least with MTextEdit
    enum TextContentType {
        //! all characters allowed
        FreeTextContentType,

        //! only integer numbers allowed
        NumberContentType,

        //! allows numbers and certain other characters used in phone numbers
        PhoneNumberContentType,

        //! allows only characters permitted in email address
        EmailContentType,

        //! allows only character permitted in URL address
        UrlContentType,

        //! allows content with user defined format
        CustomContentType
    };

    //! Type of toolbar widget
    enum ItemType {
        //! Undefined item type
        ItemUndefined,

        //! Item should be visualized as button
        ItemButton,

        //! Item should be visualized as label
        ItemLabel
    };

    //! Type of visible premiss for toolbar button
    enum VisibleType {
        //! Item's visibility will not be changed automatically
        VisibleUndefined,

        //! Item's visibility depends on text selection
        VisibleWhenSelectingText,

        //! Item is always visible
        VisibleAlways
    };

    //! Type of action
    enum ActionType {
        //! Do nothing
        ActionUndefined,

        //! Send key sequence like Ctrl+D
        ActionSendKeySequence,

        //! Send string
        ActionSendString,

        //! Send command (not implemented yet)
        ActionSendCommand,

        //! Copy selected text
        ActionCopy,

        //! Paste text from clipboard
        ActionPaste,

        //! Show some group of items
        ActionShowGroup,

        //! Hide some group of items
        ActionHideGroup,

        //! Close virtual keyboard
        ActionClose,

        //! Standard copy/paste button
        ActionCopyPaste
    };

    /*!
     * \brief State of Copy/Paste button.
     */
    enum CopyPasteState {
        //! Copy/Paste button is hidden
        InputMethodNoCopyPaste,

        //! Copy button is accessible
        InputMethodCopy,

        //! Paste button is accessible
        InputMethodPaste
    };

    /*!
     * This enum defines direction of plugin switching
     */
    enum SwitchDirection {
        SwitchUndefined, //!< Special value for uninitialized variables
        SwitchForward, //!< Activate next plugin
        SwitchBackward, //!< Activate previous plugin
        SwitchPreparationForward, //!< Prepare to switch to next plugin
        SwitchPreparationBackward, //!< Prepare to switch to previous plugin
        SwitchCanceled //!< Previous SwitchPreparation* is canceled, plugin will not be switched
    };

    enum PreeditFace {
        PreeditDefault,
        PreeditNoCandidates,
        PreeditKeyPress,      //!< Used for displaying the hwkbd key just pressed
        PreeditUnconvertible, //!< Inactive preedit region, not clickable
        PreeditActive,        //!< Preedit region with active suggestions

    };

    enum HandlerState {
        OnScreen,
        Hardware,
        Accessory
    };

    /// \brief Key event request type for \a MInputContext::keyEvent().
    enum EventRequestType {
        EventRequestBoth,         //!< Both a Qt::KeyEvent and a signal
        EventRequestSignalOnly,   //!< Only a signal
        EventRequestEventOnly     //!< Only a Qt::KeyEvent
    };

     /*!
      * This enum contains possible values for all the modes that are shown in the
      * Input mode indicator.
      */
    enum InputModeIndicator {
        NoIndicator,                 //!< No indicator should be shown
        LatinLowerIndicator,         //!< Latin lower case mode
        LatinUpperIndicator,         //!< Latin upper case mode
        LatinLockedIndicator,        //!< Latin caps locked mode
        CyrillicLowerIndicator,      //!< Cyrillic lower case mode
        CyrillicUpperIndicator,      //!< Cyrillic upper case mode
        CyrillicLockedIndicator,     //!< Cyrillic caps locked mode
        ArabicIndicator,             //!< Arabic mode
        PinyinIndicator,             //!< Pinyin mode
        ZhuyinIndicator,             //!< Zhuyin mode
        CangjieIndicator,            //!< Cangjie mode
        NumAndSymLatchedIndicator,   //!< Number and Symbol latched mode
        NumAndSymLockedIndicator,    //!< Number and Symbol locked mode
        DeadKeyAcuteIndicator,       //!< Dead key acute mode
        DeadKeyCaronIndicator,       //!< Dead key caron mode
        DeadKeyCircumflexIndicator,  //!< Dead key circumflex mode
        DeadKeyDiaeresisIndicator,   //!< Dead key diaeresis mode
        DeadKeyGraveIndicator,       //!< Dead key grave mode
        DeadKeyTildeIndicator        //!< Dead key tilde mode
    };

    enum InputMethodMode {
        //! Normal mode allows to use preedit and error correction
        InputMethodModeNormal,

        //! Virtual keyboard sends QKeyEvent for every key press or release
        InputMethodModeDirect,

        //! Used with proxy widget
        InputMethodModeProxy
    };

    /*!
     * PreeditTextFormat defines the text format for part of the preedit string
     * specified by start and length.
     *
     * \sa PreeditFace.
     */
    struct PreeditTextFormat {
        int start;
        int length;
        PreeditFace preeditFace;

        PreeditTextFormat()
            : start(0), length(0), preeditFace(PreeditDefault)
        {};

        PreeditTextFormat(int s, int l, const PreeditFace &face)
            : start(s), length(l), preeditFace(face)
        {};
    };

    //! extensions for Qt::inputMethodQuery
    enum InputMethodQueryExtensions {
        VisualizationPriorityQuery = 10001, //!< Tells if input method widget wants to have high
        //!< priority for visualization. Input method should
        //!< honor this and stay out of widgets space.
        PreeditRectangleQuery,      //!< Retrieve bounding rectangle for current preedit text.
        ImCorrectionEnabledQuery,   //!< explicit correction enabling for text entries
        ImModeQuery,                //!< Retrieve mode: normal, direct or proxy
        InputMethodAttributeExtensionIdQuery, //!< attribute extension identifier for text entry
        InputMethodAttributeExtensionQuery //!< attribute extension file name for text entry
    };
}

Q_DECLARE_METATYPE(MInputMethod::TextContentType)
Q_DECLARE_METATYPE(MInputMethod::Orientation)
Q_DECLARE_METATYPE(MInputMethod::OrientationAngle)
Q_DECLARE_METATYPE(MInputMethod::InputMethodMode)
Q_DECLARE_METATYPE(MInputMethod::InputMethodQueryExtensions)

#endif
