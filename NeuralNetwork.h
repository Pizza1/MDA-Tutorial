#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "Reservoir.h"
#include "Neuron.h"
#include "utils.h"
#include "global.h"

class NeuralNetwork
{
    public:
        /**
         * @brief Default Constructor
         */
        NeuralNetwork();

        /**
         * @brief Constructor that initializes its neurons based on the file read.
         * @arg filename Accepts a string for the filen name of the network matrix.
         */
        NeuralNetwork(char* filename);

        void linkSensor(Neuron* sensor, Neuron* target);
        void linkMotor(Neuron* target, Neuron* motor);
        void train();
        void updateSensors();
        void process();
        void cueEvolvingBackPropagation(Neuron* motor, bool reinforce);
        void determineState();

        /** Default destructor */
        virtual ~NeuralNetwork();
    protected:
    private:

        int numReservoirs;
        int resDimension;
        int numSensors;
        int numMotors;
        int maxInputs;
        int maxAxonLength;
        int maxSynapses;

        bool criticalPeriod;
        bool sensitivityPeriod;
        Neuron* sensors[NUM_SENSORS];
        Reservoir* reservoir[NUM_RESERVOIRS];
        Neuron* motors[NUM_MOTORS];
};

#endif // NEURALNETWORK_H
