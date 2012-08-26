//
//  SpotifyController.h
//  FireBreath
//
//  Created by Dany Joumaa on 8/25/12.
//
//

#ifndef FireBreath_SpotifyController_h
#define FireBreath_SpotifyController_h

#include <boost/shared_ptr.hpp>
#include <stdexcept>

struct ControllerContext;
typedef boost::shared_ptr<ControllerContext> ControllerContextPtr;

class SpotifyController {
public:
    struct InitializationException : std::runtime_error {
        InitializationException(const char* const what) : std::runtime_error(what) {}
    };
    
    SpotifyController();
    ~SpotifyController();
    
    void playOrPause();
    void goToPreviousTrack();
    void goToNextTrack();
    bool isSpotifyPlaying();
    bool isShuffling();
    void setShuffling(bool shuffling);
    bool isRepeating();
    void setRepeating(bool repeating);
    
private:
    boost::shared_ptr<ControllerContext> m_context;
};

#endif
