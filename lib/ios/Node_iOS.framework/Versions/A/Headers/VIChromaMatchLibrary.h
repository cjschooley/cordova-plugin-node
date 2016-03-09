//
//  VIChromaMatchLibrary.h
//  Node_iOS
//
//  Created by Andrew T on 7/7/15.
//  Copyright (c) 2015 Variable, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@class VIChromaMatchSwatch;



@interface VIChromaMatchLibrary : NSObject
@property int b2id;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *vendorName;
@property (readonly, nonatomic) NSString *displayName;

-(NSArray *) fetchSwatches;
-(VIChromaMatchSwatch *) fetchSwatchForCode:(NSString*)code;

-(BOOL)isCompatibleWithChromaSerial:(NSString*)serial;
- (NSDictionary *) json;

@end
