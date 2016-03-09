//
//  VIChromaMatchExternalLibrary.h
//  Node_iOS
//
//  Created by Andrew T on 8/27/15.
//  Copyright (c) 2015 Variable, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VIChromaMatchExternalLibrary : NSObject

@property int b2id;
@property (strong, nonatomic) NSString *name;
@property (strong, nonatomic) NSString *vendorName;
@property (strong, nonatomic) NSString *json_data;
@property (strong, nonatomic) NSArray *countries;
@property (strong, nonatomic) NSString *textureType;
@property int updatedAt;

@end
