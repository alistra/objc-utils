#pragma mark - Shared

// do the block inside, only if it wasn't executed in last 20 seconds, for use in e.g. error alert view presenting

typedef void (^SimpleBlock)();

#define timedLock(seconds, block) do {\
    SimpleBlock blockobj = block;\
    static NSTimeInterval lockTime = 0.0; \
    if (lockTime < [[[NSDate alloc] init] timeIntervalSinceReferenceDate]) {\
        lockTime = [[[NSDate alloc] initWithTimeIntervalSinceNow:seconds] timeIntervalSinceReferenceDate];\
        blockobj();\
    }\
} while (0)

#define DebugLog( s, ... ) NSLog( @"<%@:(%d) %@> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, NSStringFromSelector(_cmd), [NSString stringWithFormat:(s), ##__VA_ARGS__])

#define WarningLog( s, ... ) NSLog( @"<%@:(%d) %@> WARNING: %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, NSStringFromSelector(_cmd), [NSString stringWithFormat:(s), ##__VA_ARGS__])

#define ErrorLog( s, ... ) NSLog( @"<%@:(%d) %@> ERROR: %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, NSStringFromSelector(_cmd), [NSString stringWithFormat:(s), ##__VA_ARGS__])

#pragma mark - OS X

#define appDelegate ((AppDelegate*) [NSApplication sharedApplication].delegate)

#define errorAlert(str, infoStr) do {\
    NSAlert *alert = [NSAlert alertWithMessageText:str\
                                     defaultButton:NSLocalizedString(@"OK", @"OK - alert window")\
                                   alternateButton:nil\
                                       otherButton:nil\
                         informativeTextWithFormat:infoStr];\
    [alert runModal]; } while(0)

#pragma mark - iOS

// presenting the error alert to the user

#define errorAlertView(str) do {\
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Error", @"Error title message")\
                                                        message:str\
                                                       delegate:nil\
                                              cancelButtonTitle:@"OK"\
                                              otherButtonTitles:nil];\
                             [alertView show];\
    } while (0);


#define iPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define iPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
