//
//  VIChromaMatchSwatch.h
//  Node_iOS
//
//  Created by Andrew T on 7/7/15.
//  Copyright (c) 2015 Variable, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VIChromaMatchLibrary.h"
#import "VTHSBColor.h"

@interface VIChromaMatchSwatch : NSObject

@property int b2id;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString* code;
@property float order;//order as given by physical deck, etc
@property int level3Index;
@property int level2Index;
@property int level1Index;
@property (strong, nonatomic) NSString* metaData;
@property float R;
@property float G;
@property float B;
@property (strong, nonatomic) VIChromaMatchLibrary* library;
@property (nonatomic, readonly) VTHSBColor *hsbColor;
@property (nonatomic, readonly) UIColor *uiColor;

+ (VIChromaMatchSwatch *)fetchSwatchWithB2Id: (int) b2id;
- (NSDictionary *) json;

@end
