//
//  MscSCEP.h
//  MscSCEP
//
//  Created by Microsec on 2014.01.13..
//  Copyright (c) 2014 Microsec. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MscSCEPResponse.h"

#import "MscX509Common/MscRSAKey.h"
#import "MscX509Common/MscCertificate.h"

#import "MscHTTPSURLConnection/MscHTTPSURLConnection.h"

@interface MscSCEP : NSObject

-(MscSCEP*) init __attribute__((unavailable("please, use initWithURL for initialization")));
-(id)initWithURL:(NSURL*)_url;

-(NSArray*)downloadCACertificateWithValidatorDelegate:(id<MscHTTPSValidatorDelegate>)validatorDelegate error:(MscSCEPError**)error;

-(MscSCEPResponse*)enrollWithRSAKey:(MscRSAKey*)rsaKey certificateSigningRequest:(MscCertificateSigningRequest*)certificateSigningRequest certificate:(MscCertificate*)certificate caCertificate:(MscCertificate*)caCertificate createPKCS12:(BOOL)createPKCS12 pkcs12Password:(NSString*)pkcs12Password validatorDelegate:(id<MscHTTPSValidatorDelegate>)validatorDelegate error:(MscSCEPError**)error;

-(MscSCEPResponse*)downloadCRLWithRSAKey:(MscRSAKey*)rsaKey certificate:(MscCertificate*)certificate issuer:(MscX509Name*)issuer serial:(NSString*)serial caCertificate:(MscCertificate*)caCertificate validatorDelegate:(id<MscHTTPSValidatorDelegate>)validatorDelegate error:(MscSCEPError**)error;

-(MscSCEPResponse*)downloadCertificateWithRSAKey:(MscRSAKey*)rsaKey issuer:(MscX509Name*)issuer serial:(NSString*)serial caCertificate:(MscCertificate*)caCertificate validatorDelegate:(id<MscHTTPSValidatorDelegate>)validatorDelegate error:(MscSCEPError**)error;

@end
