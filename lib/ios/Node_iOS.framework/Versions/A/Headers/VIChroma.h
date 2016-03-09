//
//  VIChroma.h
//  Node_iOS
//
//  Created by Wade Gasior on 7/29/15.
//  Copyright (c) 2015 Variable, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@class VIChromaSession;

@interface VIChroma : NSObject

/** Starts an API session using a provided API key and Color Library access key
    For use with Chroma Match apps
 **/
+ (void) startWithKey:(NSString*)apiKey andColorLibraryKey: (NSString *)colorKey onSuccess: (void (^)(VIChromaSession *))onSuccessCallback onError: (void (^)(NSError *))onErrorCallback;


/** Starts an API session using a provided API key
    For use with Chroma apps where color library access is not required
 **/
+ (void) startWithKey:(NSString*)apiKey onSuccess: (void (^)(VIChromaSession *))onSuccessCallback onError: (void (^)(NSError *))onErrorCallback;
@end
