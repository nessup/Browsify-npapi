#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for Browsify
#
#\**********************************************************/

set(PLUGIN_NAME "Browsify")
set(PLUGIN_PREFIX "BRO")
set(COMPANY_NAME "DanyJoumaa")

# ActiveX constants:
set(FBTYPELIB_NAME BrowsifyLib)
set(FBTYPELIB_DESC "Browsify 1.0 Type Library")
set(IFBControl_DESC "Browsify Control Interface")
set(FBControl_DESC "Browsify Control Class")
set(IFBComJavascriptObject_DESC "Browsify IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "Browsify ComJavascriptObject Class")
set(IFBComEventSource_DESC "Browsify IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 2176e722-f7d2-59f4-aa2b-7ed8072af9f7)
set(IFBControl_GUID 437b93c9-f4db-54a1-9cda-0dd13978c0a7)
set(FBControl_GUID a5d5abd9-cf69-58fc-b267-ec115e5ae045)
set(IFBComJavascriptObject_GUID 1af01451-0c57-59ad-a552-c444c851e25e)
set(FBComJavascriptObject_GUID da498132-0cc3-5655-9111-05e8edc105f4)
set(IFBComEventSource_GUID 37ca10be-f484-5d19-bc02-fd008e61f38e)

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "DanyJoumaa.Browsify")
set(MOZILLA_PLUGINID "joumaa.com/Browsify")

# strings
set(FBSTRING_CompanyName "Dany Joumaa")
set(FBSTRING_PluginDescription "Plugin for controlling Spotify from within a web browser")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2012 Dany Joumaa")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "Browsify")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "Browsify")
set(FBSTRING_MIMEType "application/x-browsify")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 0)
set(FBMAC_USE_COCOA 0)
set(FBMAC_USE_COREGRAPHICS 0)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
