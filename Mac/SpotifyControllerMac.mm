#import <Foundation/Foundation.h>

#include "../SpotifyController.h"

struct ControllerContext
{
    std::string error;
    
    ControllerContext() {}
};

namespace
{
    ControllerContextPtr make_context()
    {
        ControllerContextPtr context(new ControllerContext);
        return context;
    }
}

NSAppleEventDescriptor *
_executeScript(NSString *scriptString)
{
    NSAppleScript *script = [[NSAppleScript alloc] initWithSource:scriptString];
    NSDictionary *error = nil;
    NSAppleEventDescriptor *ret = [script executeAndReturnError:&error];
    [script release];
    
    return ret;
}

SpotifyController::SpotifyController()
{
    try
    {
        m_context = make_context();
    }
    catch(const InitializationException& e)
    {
        m_context = ControllerContextPtr(new ControllerContext);
        m_context->error = e.what();
        throw;
    }
}

SpotifyController::~SpotifyController()
{
    
}

void
SpotifyController::playOrPause()
{
    system( "touch ~/hey" );
    _executeScript( @"tell application \"Spotify\" to playpause" );
}

void
SpotifyController::goToPreviousTrack()
{
    _executeScript( @"tell application \"Spotify\" to previous track" );
}

void
SpotifyController::goToNextTrack()
{
    _executeScript( @"tell application \"Spotify\" to next track" );
}

bool
SpotifyController::isSpotifyPlaying()
{
    return [_executeScript( @"tell application \"Spotify\" to if player state is playing then return true" ) booleanValue];
}

bool
SpotifyController::isShuffling()
{
    return [_executeScript( @"tell application \"Spotify\" to if shuffling and shuffling enabled then return true") booleanValue];
}

void
SpotifyController::setShuffling(bool shuffling)
{
    NSString *scriptString = [NSString stringWithFormat:@"tell application \"Spotify\" to set shuffling to %@", (shuffling ? @"true" : @"false"), nil];
    _executeScript( scriptString );
}

bool
SpotifyController::isRepeating()
{
    return [_executeScript( @"tell application \"Spotify\" to if repeating and repeating enabled then return true") booleanValue];
}

void
SpotifyController::setRepeating(bool repeating)
{
    NSString *scriptString = [NSString stringWithFormat:@"tell application \"Spotify\" to set repeating to %@", (repeating ? @"true" : @"false"), nil];
    _executeScript( scriptString );
}

