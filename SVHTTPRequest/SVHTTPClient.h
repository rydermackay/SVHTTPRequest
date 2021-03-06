//
//  SVHTTPClient.h
//
//  Created by Sam Vermette on 15.12.11.
//  Copyright 2011 samvermette.com. All rights reserved.
//
//  https://github.com/samvermette/SVHTTPRequest
//

#import <Foundation/Foundation.h>

@class SVHTTPRequest;

@interface SVHTTPClient : NSObject

+ (id)sharedClient;

- (void)setBasicAuthWithUsername:(NSString*)username password:(NSString*)password;

- (SVHTTPRequest *)GET:(NSString*)path parameters:(NSDictionary*)parameters completion:(void (^)(id response, NSHTTPURLResponse *urlResponse, NSError *error))completionBlock;
- (SVHTTPRequest *)GET:(NSString*)path parameters:(NSDictionary*)parameters saveToPath:(NSString*)savePath progress:(void (^)(float progress))progressBlock completion:(void (^)(id response, NSHTTPURLResponse *urlResponse, NSError *error))completionBlock;

- (SVHTTPRequest *)POST:(NSString*)path parameters:(NSDictionary*)parameters completion:(void (^)(id response, NSHTTPURLResponse *urlResponse, NSError *error))completionBlock;
- (SVHTTPRequest *)PUT:(NSString*)path parameters:(NSDictionary*)parameters completion:(void (^)(id response, NSHTTPURLResponse *urlResponse, NSError *error))completionBlock;
- (SVHTTPRequest *)DELETE:(NSString*)path parameters:(NSDictionary*)parameters completion:(void (^)(id response, NSHTTPURLResponse *urlResponse, NSError *error))completionBlock;

- (void)cancelRequestsWithPath:(NSString*)path;
- (void)cancelAllRequests;

// header values common to all requests, e.g. API keys
- (void)addValue:(NSString *)value forHTTPHeaderField:(NSString *)field;
- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;

@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *basePath;
@property (nonatomic, strong) NSString *userAgent;

@property (nonatomic, readwrite) BOOL sendParametersAsJSON;
@property (nonatomic, readwrite) NSURLRequestCachePolicy cachePolicy;


// hook for subclasses to override and process response
// default implementation simply invokes completion block using parameters

- (void)operationDidFinishWithResponse:(id)response
                           urlResponse:(NSHTTPURLResponse *)urlResponse
                                 error:(NSError *)error
                            completion:(void (^)(id response, NSHTTPURLResponse *urlResponse, NSError *error))completion;

@end