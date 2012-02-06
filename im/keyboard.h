/***************************************************************************
 *   Copyright (C) 2012~2012 by CSSlayer                                   *
 *   wengxt@gmail.com                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef FCITX_KEYBOARD_H
#define FCITX_KEYBOARD_H

#include <iconv.h>
#include <enchant/enchant.h>
#include <fcitx/ime.h>
#include <fcitx-utils/utarray.h>
#include <fcitx-config/fcitx-config.h>
#include "rules.h"

#define FCITX_KEYBOARD_MAX_BUFFER 20
#define FCITX_KEYBOARD_MIN_HINT_LENGTH 4
#define FCITX_MAX_COMPOSE_LEN 7

#define _(x) dgettext("fcitx-keyboard", (x))

typedef struct _FcitxKeyboardConfig {
    FcitxGenericConfig gconfig;
    boolean bOnlyHintWordWithSamePrefix;
    boolean bCommitWithExtraSpace;
    boolean bEnableWordHint;
    boolean bUseEnterToCommit;
    FcitxHotkey hkToggleWordHint[2];
    FcitxHotkey hkAddToUserDict[2];
} FcitxKeyboardConfig;

typedef struct _FcitxKeyboard {
    struct _FcitxInstance* owner;
    EnchantBroker* broker;
    UT_array* enchantLanguages;
    FcitxKeyboardConfig config;
    FcitxXkbRules* rules;
    char dictLang[6];
    EnchantDict* dict;
    iconv_t iconv;
} FcitxKeyboard;

typedef struct _FcitxKeyboardLayout {
    FcitxKeyboard* owner;
    char* layoutString;
    char buffer[FCITX_KEYBOARD_MAX_BUFFER + UTF8_MAX_LENGTH + 1];
    int cursorPos;
    uint composeBuffer[FCITX_MAX_COMPOSE_LEN + 1];
    int n_compose;
    char* variantString;
} FcitxKeyboardLayout;

CONFIG_BINDING_DECLARE(FcitxKeyboardConfig);

#endif
