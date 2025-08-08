//
//  ConvertTool.h
//  vietypekey
//
//  Created by T.
//  Copyright © 2025 T. All rights reserved.
//

#ifndef ConvertTool_h
#define ConvertTool_h

#include "DataType.h"
#include <string>
using namespace std;

extern bool convertToolDontAlertWhenCompleted;
extern bool convertToolToAllCaps;
extern bool convertToolToAllNonCaps;
extern bool convertToolToCapsFirstLetter;
extern bool convertToolToCapsEachWord;
extern bool convertToolRemoveMark;
extern Uint8 convertToolFromCode;
extern Uint8 convertToolToCode;
extern int convertToolHotKey;

string convertUtil(const string& sourceString);

#endif /* ConvertTool_h */
