/**********************************************************\

  Auto-generated BrowsifyAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "BrowsifyPlugin.h"

#ifndef H_BrowsifyAPI
#define H_BrowsifyAPI

class SpotifyController;

class BrowsifyAPI : public FB::JSAPIAuto
{
public:

    BrowsifyAPI(const BrowsifyPluginPtr& plugin, const FB::BrowserHostPtr& host);
    ~BrowsifyAPI();

    BrowsifyPluginPtr getPlugin();
    
    void playOrPause();
    void goToPreviousTrack();
    void goToNextTrack();
    bool isShuffling();
    void setShuffling(bool shuffling);
    bool isRepeating();
    void setRepeating(bool repeating);
    
    // Read only property
    bool isSpotifyPlaying();

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

private:
    typedef boost::shared_ptr<SpotifyController> SpotifyControllerPtr;
    
    BrowsifyPluginWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;
    SpotifyControllerPtr m_player;

    std::string m_testString;
};

#endif // H_BrowsifyAPI

