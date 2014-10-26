//
//  DatabaseManager.h
//  Couchbase Mobile
//
//  Created by Jan Lehnardt on 27/11/2010.
//  Copyright 2011 Couchbase, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy of
// the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations under
// the License.
//

#import <Foundation/Foundation.h>
#import "CCouchDBDocument.h"
#import "CouchDBClientTypes.h"

typedef void (^DatabaseManagerSuccessHandler)();
typedef void (^DatabaseManagerErrorHandler)(id error);

@class CCouchDBServer;
@class CCouchDBDatabase;

@interface DatabaseManager : NSObject {
	CCouchDBServer *server;
	CCouchDBDatabase *database;
	NSMutableDictionary *connections;
	id delegate;
}

@property (nonatomic, readonly) CCouchDBServer *server;
@property (nonatomic, readonly)CCouchDBDatabase *database;
@property (nonatomic, weak) id delegate;
@property (nonatomic, retain) NSMutableDictionary *connections;

+(DatabaseManager *)sharedManager:(NSURL *)dbURL dbName:(NSString*)name;
+(DatabaseManager *)sharedManager:(NSURL *)dbURL;

// delete and recreate the database
- (void) recreateDatabaseOnSuccess:(CouchDBSuccessHandler) success onError:(CouchDBFailureHandler)error;
-(void)syncFrom:(NSString *)from to:(NSString *)to onSuccess:(DatabaseManagerSuccessHandler)success onError:(DatabaseManagerErrorHandler) error;
-(void)deleteDocument:(CCouchDBDocument *)inDocument;
-(id)init:(NSURL *)dbURL;
-(id)init:(NSURL *)dbURL dbName:(NSString*)name;
@end
