//
//  VIChromaMatchResult.h
//  Node
//
//  Created by Wade Gasior on 3/19/14.
//  Copyright (c) 2014 Variable, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VIChromaMatchSwatch.h"
#import "VTLabColor.h"

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#endif

@interface VIChromaMatchResult : NSObject
@property (strong, nonatomic, readonly) VIChromaMatchSwatch *swatch;
@property (nonatomic, readonly) double deltaEFromReading;
@property (nonatomic, readonly) NSDictionary * json;

+ (VIChromaMatchResult *)result;
+ (VIChromaMatchResult *)resultWithdE: (double)dE swatch:(VIChromaMatchSwatch *)swatch;

@end
