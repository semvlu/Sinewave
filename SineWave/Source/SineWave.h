/*
  ==============================================================================

    SineWave.h
    Created: 8 Jun 2021 3:49:03pm
    Author:  SEM

  ==============================================================================
*/

#pragma once

class SineWave
{
public:
    void prepareToPlay (double sampleRate)
    {
        period = 1.0f / sampleRate;
        
    }
    
    float getNextSample(float frequency)
    {
        jassert (period > 0.0f);
        if (currentTime >= 1.0f)
        {
            currentTime = 0.0f;
        }
        float sample = std::sin (2.0f * juce::MathConstants<float>::pi * frequency * currentTime + 0.0f);
        currentTime += period;
        return sample;
    }
    
private:
    float period {0.0f};
    float currentTime {0.0f};
};
