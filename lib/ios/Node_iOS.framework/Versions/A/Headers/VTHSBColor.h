//
//  VTHSBColor.h
//  Node_iOS
//
//  Copyright (c) 2015 Variable, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@class UIColor;

@interface VTHSBColor : NSObject

@property (nonatomic, readonly) double hue;
@property (nonatomic, readonly) double saturation;
@property (nonatomic, readonly) double brightness;
@property (nonatomic, readonly) double h;
@property (nonatomic, readonly) double s;
@property (nonatomic, readonly) double b;

+ (VTHSBColor *)colorWithUIColor: (UIColor *)color;

@end
