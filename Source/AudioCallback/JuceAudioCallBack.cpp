#include "JuceAudioCallBack.h"

CJuceAudioCallBack::CJuceAudioCallBack(void)
{
}


CJuceAudioCallBack::~CJuceAudioCallBack(void)
{
}

void CJuceAudioCallBack::audioDeviceAboutToStart (AudioIODevice* device)
{
    String debuginfo;
    debuginfo << "Sample rate:" << device->getCurrentSampleRate() << ", Buffer size:" << device->getCurrentBufferSizeSamples();
    DBG(debuginfo);
}

void CJuceAudioCallBack::audioDeviceStopped()
{
    //device stopped.
}

//处理录音数据/填充播放数据的回调函数
//每一帧中包含了若干个采样点。这个函数会在每一帧完成后调用。
//numSamples       - 这一帧中包含多少个采样点
//inputChannelData - 录音数据，这些数据是按通道保存的。比如说立体声(双通道)录音，
//                   则左通道在 inputChannelData[0]中,右通道在inputChannelData[1]中。
//                   左通道的第一个数据则是 inputChannelData[0][0]
//numInputChannels - 有多少个录音通道。
//outputChannelData- 要播放的数据。与录音数据结构一致，只需要按要求填充这个指针就可以得到正确的声音。
//numOutputChannels- 有多少个播放通道。

//一般而言，我们可以强行指定参数，则numSamples，numInputChannels，numOutputChannels是不会改变的。
//不过为了代码的通用性，建议在代码中加入判断。以免以后这三个值发生变化时代码无法正常工作。

void CJuceAudioCallBack::audioDeviceIOCallback (const float** inputChannelData,
                                    int numInputChannels,
                                    float** outputChannelData,
                                    int numOutputChannels,
                                    int numSamples)
{
    inputChannelData = inputChannelData;
    numInputChannels += 0;
    float sampleval;
    
    for(int i = 0;i < numOutputChannels;i++)
    {
        for (int j = 0; j < numSamples; j++)
        {
            //outputChannelData[i][j] = 0.0f;
            outputChannelData[i][j] = sin(j*3.1415926 * 4 / 48);
        }
    }
}

