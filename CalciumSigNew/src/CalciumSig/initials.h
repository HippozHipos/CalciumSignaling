#include <vector>
#include <cmath>

struct initials
{
    initials()
    {
        constexpr int n = 3;
        constexpr int m = 3;

        laticeset.resize((int)((cell_amount / lattice_space) * n * m));
        std::fill(laticeset.begin(), laticeset.end(), 0);

        /* this is what originl_values contains the equivelant code for.
        ini = [100, 0, 0.05, 15, 0.1, 2.02, 0.1, 4000, 50, 1.5, 50, 0.3, 8, 0.05, 0.15, 0.15, 0.1, 0.1, 4, 0, 0, 0.5, D,
            (3.1416 * ((float(x) / 2.0) * *2)), 0.0006, 2.5, 2.2, phh[0], phl[0], plh[0]] * int(space / l) * n * m
        */
        double original_values[30] =
        {
            100.0, 0.0, 0.05, 15.0, 0.1, 2.02, 0.1, 4000.0, 50.0, 1.5, 50.0, 0.3, 8.0, 0.05, 0.15, 0.15, 0.1, 0.1, 4.0, 0, 0, 0.5, (double)diffusion_coeff,
            (3.1416 * std::pow((cell_length / 2.0), 2)), 0.0006, 2.5, 2.2, probabilities::phh[0], probabilities::phl[0], probabilities::plh[0]
        };

        ini.resize((int)((cell_amount / lattice_space) * n * m));
        for (int i = 0; i < ini.size(); i++)
        {
            ini[i] = original_values[i % 30];
        }
    }

    int diffusion_coeff = 122500;                                 // diffusion coefficient(adapted) - media is the intracellular astrocyte
    double lattice_space = 0.5;                                   // space of each lattive in micro meters
    int cell_amount = 10;                                         // variable to define the amount of cells(depricated ? )
    int cell_length = 5;

    int time = 0;                                                 // initialize time variable(simulation time)
    int tini = 0;                                                 // represents transmission time(transmit my bits)

    //tend = 2;                                                   // represents ends of transmission time

    std::vector<int> laticeset;
    std::vector<double> calcium_concentration_tx;                 // variable to monitor the calcium concentration in Tx
    std::vector<double> calcium_concentration_rx;                 // variable to monitor the calcium concentration in Rx
    std::vector<double> T;                                        // will monitor time(guillespie we calculate time per reaction)
    std::vector<double> ini;

    int number_of_rec = 29;                                       // number of reactions per cell
    int number_of_var = 30;                                       // number of variables per cell
};