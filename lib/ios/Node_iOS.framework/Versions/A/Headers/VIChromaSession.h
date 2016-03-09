//
//  VINodeAPIAccount.h
//  Node_iOS
//
//  Copyright (c) 2015 Variable, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VIChromaMatchSession : NSObject

@property (strong, nonatomic) NSString *colorLibraryKey;
@property BOOL isValid;
@property (strong, nonatomic) NSDate *expirationDate;
@property (strong, nonatomic) NSDate *activationDate;

@end

@interface VIChromaSession : NSObject

+ (instancetype) currentSession;

@property (strong, nonatomic) NSString *apiKey;
@property (strong, nonatomic) VIChromaMatchSession *chromaMatchSession;
@property BOOL isValid;
@property BOOL isDbRefreshed;

@end
