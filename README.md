# Exchange Rate Navigator


![Alt text](./graphPhoto.png)

Imagine you are planning a trip from the United States to India and you want to convert your U.S. Dollars (USD) into Indian Rupees (INR). You want to ensure that you are getting the best possible exchange rate, as currency conversion fees can significantly impact your travel budge. You need a way to find the best route(having high exchange rate) for exchanging USD to INR by potentially converting through other currencies to maximize the amount of INR you receive. For example, you might exchange USD to Euros (EUR), then from EUR to GBP (British Pounds), and finally from GBP to INR. Using Exchange Rate Navigator, you can find the best exchange rate while converting to another currency. This project uses set approach Dijkstra's algorithm for getting high exchange rates and best understanding of graphs.


## Overview

The **Exchange Rate Navigator** is a C++ application designed to find the best exchange rate path between currencies. This program uses a graph data structure to represent currencies as nodes and their exchange rates as edges. The application can help users determine how to convert one currency into another by following the best possible exchange rates.
## Assumptions

- **Predefined Exchange Rates**: The application currently relies on a static set of exchange rates, which may not reflect real-time market values.
- **Currency Availability**: The implemented exchange rates only cover a limited set of currencies. 
- **Input Validity**: The application assumes that valid currency codes are provided as input(currently JPY GBP AUD CAD EUR USD INR).
- **No API Key Requirement**: The current version of the application does not utilize an external API that requires an API key for access. This simplifies usage but limits the ability to fetch live data.

## Features

- **Graph Representation**: Currencies are represented as nodes, and exchange rates are edges connecting these nodes.
- **Best Path Calculation**: The application calculates the best path from a source currency to a destination currency based on exchange rates using Dijkstra's algorithm.

## Structures and Classes

The project includes the following main components:

- **Edge**: A struct that represents an edge in the graph, which includes a destination currency and its exchange rate.
- **ExchangeRateNavigator**: A class that manages the adjacency list of currencies and implements the logic to find the best path based on exchange rates using Dijkstra's algorithm.

### Key Functions

- `initializeadjList()`: Initializes the adjacency list with predefined exchange rates between currencies.
- `findBestPath(const string source, const string destination)`: Computes the best exchange rate path from the source currency to the destination currency.
## Future Scope:
- Future versions will aim to include more currencies and exchange rates to provide a broader spectrum of conversions.
## Usage

To run the application, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/LohithMarneni/Exchange-Rate-Navigator.git

2. Navigate to the project directory:
    ```bash
    cd Exchange-Rate-Navigator
3. Compile the code:
    ```bash
    g++ main.cpp -o ExchangeRateNavigator
4. Execute the program:
    ```bash
    ./ExchangeRateNavigator

# Future Work

API Integration:

 The current implementation does not utilize an API for fetching live exchange rates. Future updates will include fetching data from currency APIs to ensure the rates are up-to-date.

User Input:

 Implement functionality to allow users to input their own source and destination currencies.

# License
    ```bash
    Feel free to modify any sections as needed to better fit your project or personal preferences!

