#ifndef RAPP_ROBOT_COMMUNICATION
#define RAPP_ROBOT_COMMUNICATION
#include "Includes.ihh"

/**
 * @class Communication
 * @brief Class which defines the interface for Robot communication capabilities (speaking, listening)
 * @date 03-August-2015
 * @author Maciej Stefańczyk <stefaczyk.maciek@gmail.com>
 * @note This class uses pimpl pattern to make ABI as stable as possible when deploying new library versions
 */

namespace rapp {
namespace robot {

class CommunicationImpl;

class Communication
{
  public:
  
    /// List of all possible languages
    enum class Language {ENGLISH, GREEK};
      
    /// Produce Audio from robot's speakers
    bool playAudio(const std::string & file_path, double position, double volume, double balance, bool play_in_loop); 
    
    /// Say given sentence in selected language
    bool textToSpeech(const std::string & str, Language language = Language::ENGLISH);

  private:
    CommunicationImpl * pimpl;
};


} // namespace robot
} // namespace rapp

#endif // RAPP_ROBOT_COMMUNICATION
