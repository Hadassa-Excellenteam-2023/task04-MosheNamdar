# task04-MosheNamdar
task04-MosheNamdar created by GitHub Classroom

In the provided code, a `std::vector` is used to store a collection of cities in a `Controller` class. The `Controller` class has a constructor that takes a filename and loads the cities from a file. It also includes a `searchCities` function that takes a selected city, a radius, and a norm value as parameters.

The `searchCities` function first searches for the selected city within the vector of cities. If the city is not found, an error message is displayed. Otherwise, it calculates the distance between the selected city and each city in the vector using the specified norm. Cities within the given radius are added to a new vector called `citiesWithinRadius`.

The `citiesWithinRadius` vector is then sorted based on the distance from the selected city. The number of cities within the radius is displayed, followed by the number of cities that are located to the north of the selected city. Finally, the names of the cities within the radius are displayed.

The `Controller` class also includes a `calculateDistance` function, which calculates the distance between two cities based on the specified norm. Additionally, it has a `loadCities` function that reads city data from a file and populates the `cities` vector.

The use of a vector in this code provides efficient random access, allows for dynamic size, facilitates compatibility with standard library algorithms, and offers simplicity in managing the collection of cities. 
