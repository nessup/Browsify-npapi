/**********************************************************\

  Auto-generated BrowsifyAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include "BrowsifyAPI.h"
#include "SpotifyController.h"


BrowsifyAPI::BrowsifyAPI(const BrowsifyPluginPtr& plugin, const FB::BrowserHostPtr& host) :
m_plugin(plugin), m_host(host)
{

    
    try
    {
        m_player  = SpotifyControllerPtr(new SpotifyController);
        m_valid   = true;
    }
    catch(const SpotifyController::InitializationException&)
    {
        m_host->htmlLog("failed to initialize spotify controller");
    }
    
    registerMethod("playOrPause",      make_method(this, &BrowsifyAPI::playOrPause));
    registerMethod("goToPreviousTrack",      make_method(this, &BrowsifyAPI::goToPreviousTrack));
    registerMethod("goToNextTrack",      make_method(this, &BrowsifyAPI::goToNextTrack));
    
    // Read-write property
    registerProperty("shuffling",
                     make_property(this,
                                   &BrowsifyAPI::isShuffling,
                                   &BrowsifyAPI::setShuffling));
    registerProperty("repeating",
                     make_property(this,
                                   &BrowsifyAPI::isRepeating,
                                   &BrowsifyAPI::setRepeating));
    
    // Read-only property
    registerProperty("version",
                     make_property(this,
                                   &BrowsifyAPI::get_version));
    registerProperty("spotifyPlaying",
                     make_property(this,
                                   &BrowsifyAPI::isSpotifyPlaying));
}

///////////////////////////////////////////////////////////////////////////////
/// @fn BrowsifyAPI::~BrowsifyAPI()
///
/// @brief  Destructor.  Remember that this object will not be released until
///         the browser is done with it; this will almost definitely be after
///         the plugin is released.
///////////////////////////////////////////////////////////////////////////////
BrowsifyAPI::~BrowsifyAPI() {};

///////////////////////////////////////////////////////////////////////////////
/// @fn BrowsifyPtr BrowsifyAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
BrowsifyPluginPtr BrowsifyAPI::getPlugin()
{
    BrowsifyPluginPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}

void
BrowsifyAPI::playOrPause()
{
    m_player->playOrPause();
}
void
BrowsifyAPI::goToPreviousTrack()
{
    m_player->goToPreviousTrack();
}

void
BrowsifyAPI::goToNextTrack()
{
    m_player->goToNextTrack();
}

bool
BrowsifyAPI::isShuffling()
{
    return m_player->isShuffling();
}

void
BrowsifyAPI::setShuffling(bool shuffling)
{
    m_player->setShuffling(shuffling);
}

bool
BrowsifyAPI::isRepeating()
{
    return m_player->isRepeating();
}

void
BrowsifyAPI::setRepeating(bool repeating)
{
    m_player->setRepeating(repeating);
}

// Read-only property version

bool
BrowsifyAPI::isSpotifyPlaying()
{
    return m_player->isSpotifyPlaying();
}

std::string BrowsifyAPI::get_version()
{
    return FBSTRING_PLUGIN_VERSION;
}

