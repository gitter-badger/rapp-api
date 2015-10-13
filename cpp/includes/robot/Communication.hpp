#ifndef RAPP_ROBOT_COMMUNICATION
#define RAPP_ROBOT_COMMUNICATION
#include "Includes.ihh"

#include <string>

#include <vector>

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
  
    /// Constructor - create instance of CommunicationImpl here
    Communication(int argc, char * argv[]);
  
    ~Communication();
  
    /// List of all possible languages
    enum class Language {ENGLISH, GREEK};
      
    /// Produce Audio from robot's speakers
    bool playAudio(const std::string & file_path, double position, double volume, double balance, bool play_in_loop); 
    
    /// Say given sentence in default language
    //bool textToSpeech(const std::string & str);
    
    /// Say given sentence in selected language
    bool textToSpeech(const std::string & str, Language language = Language::ENGLISH);
    
    /// Recognize the word included in the database
    std::string wordSpotting(std::string dictionary[], int size);
    
    /// Record the audio message from the microphones by the desired time
	std::string captureAudio(int time);
	
	/// Record the audio message with silence detection
	std::string captureAudio(std::string & file_path, float waiting_time, int microphone_energy);
	
	/// Give the detected energy by the selected microphone
	int microphoneEnergy(std::string & name);
	
	/// Record the audio message to the buffer
	void voiceRecord(bool startRecording, std::vector< std::vector<unsigned char> > &audio_buffer_vector);

  private:
    CommunicationImpl * pimpl;
};


} // namespace robot
} // namespace rapp

#endif // RAPP_ROBOT_COMMUNICATION
