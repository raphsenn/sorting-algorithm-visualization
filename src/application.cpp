#include "./application.h"

Application::Application() : width(1024), height(768), window(sf::VideoMode(width, height), "SFML!"), arraySize(200)
{
  // Allocate memory for the array.
  // Fill the array with numbers from 1 to 1001.
  // Shuffle the array.
  arrayPtr = new int[arraySize];
  for (int i = 0; i < arraySize; i++) { arrayPtr[i] = i + 1; }
  shuff();
  
  // Initialize algorithms map. 
  algorithmsMap[0] = {"MergeSort", &Application::mergeSortCall};
  algorithmsMap[1] = {"BubbleSort", &Application::bubbleSort};
  algorithmsMap[2] = {"MinSort", &Application::minSort};
  currentAlgorithm = 0; // = mergeSort.

  // Load font.  
  if (!font.loadFromFile("res/VarelaRound-Regular.ttf"))
  {
    printf("Error loading Font.");
  }
}

void Application::draw()
{
  // Draw each number as a bar.
  float barX = static_cast<float>((static_cast<float>(width) / static_cast<float>(arraySize))); 
  for (int i = 0; i < arraySize; i++)
  {
    float barY = static_cast<float>(static_cast<float>(arrayPtr[i]) / static_cast<float>(arraySize + 1) * static_cast<float>(height));
    sf::RectangleShape bar;
    bar.setSize(sf::Vector2f(barY, barX));
    bar.setFillColor(sf::Color::White);
    bar.rotate(-90);
    bar.move(i * barX, height);
    window.draw(bar);
    sf::sleep(sf::microseconds(10));
  }
  // Draw text.
  sf::Text text;
  text.setFont(font);
  text.setString(std::get<0>(algorithmsMap[currentAlgorithm]));
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::White);
  window.draw(text); 
}

void Application::update()
{
  window.clear(sf::Color(0, 105, 148)); // Background color: SeaBlue RGB=(0, 105, 148).
  // window.clear(sf::Color(173, 216, 230)); // Background color: LightBlue RGB=(173, 216, 230).
  draw();
  window.display();
}

void Application::input()
{
  if (event.type == sf::Event::KeyPressed)
  {
    switch (event.key.code)
    {
      case sf::Keyboard::Enter:
        executeCurrentAlgorithm();
        break;
          case sf::Keyboard::R:
            shuff();
            break;
          case sf::Keyboard::Right:
            selectNextAlgorithm();
            break;
          case sf::Keyboard::Left:
            selectPreviousAlgorithm();
            break;
          default:
            break;
    }
  }
}

void Application::executeCurrentAlgorithm()
{
  (this->*(std::get<1>(algorithmsMap[currentAlgorithm])))(); 
}

void Application::selectNextAlgorithm()
{
  currentAlgorithm = (currentAlgorithm + 1) % algorithmsMap.size();
}

void Application::selectPreviousAlgorithm()
{
  // Ensure currentAlgorithm is non-negative
  if (currentAlgorithm > 0)
  {
    currentAlgorithm = (currentAlgorithm - 1) % algorithmsMap.size();
  } else
  {
    currentAlgorithm = algorithmsMap.size() - 1;
  }
}

void Application::shuff()
{
  // Shuffle the array.
  std::random_device rd;
  std::mt19937 g(rd());
  shuffle(arrayPtr, arrayPtr + arraySize, g);
}

void Application::run() {
  while (window.isOpen())
  {
    // sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
      input();
    }
      update();
  }
}

////////////////////////////////////////////////////////////////////////
// The Algorithms
////////////////////////////////////////////////////////////////////////

void Application::minSort()
{
  int currentMin;
  int currentMinIndex;
  int tmp;
  for (int i = 0; i < arraySize; i++)
  {
    currentMin = arrayPtr[i];
    currentMinIndex = i;
    for (int j = i; j < arraySize; j++)
    {
      if (currentMin > arrayPtr[j])
      {
        currentMin = arrayPtr[j];
        currentMinIndex = j; 
        update(); 
      }
    }
    // Perfrom swap. 
    tmp = arrayPtr[i];
    arrayPtr[i] = currentMin;
    arrayPtr[currentMinIndex] = tmp;
  }
}

void Application::bubbleSort()
{
  for (int i = 0; i < arraySize - 1; i++)
  {
    for (int j = 0; j < arraySize - i - 1; j++)
    {
      if (arrayPtr[j] > arrayPtr[j + 1])
      {
        // Swap elements if they are in the wrong order
        int temp = arrayPtr[j];
        arrayPtr[j] = arrayPtr[j + 1];
        arrayPtr[j + 1] = temp;
        update(); // Update visualization after each swap
      }
    }
  }
}

void Application::merge(int low, int mid, int high)
{
  int n1 = mid - low + 1;
  int n2 = high - mid;

  // Create temporary arrays
  int L[n1], R[n2];

  // Copy data to temporary arrays L[] and R[]
  for (int i = 0; i < n1; i++)
    L[i] = arrayPtr[low + i];
  for (int j = 0; j < n2; j++)
    R[j] = arrayPtr[mid + 1 + j];

  // Merge the temporary arrays back into arrayPtr[low..high]
  int i = 0, j = 0, k = low;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arrayPtr[k] = L[i];
      i++;
    } else
    {
      arrayPtr[k] = R[j];
      j++;
    }
    k++;
    update(); // Update visualization after each comparison
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
      arrayPtr[k] = L[i];
      i++;
      k++;
      update(); // Update visualization after each comparison
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
      arrayPtr[k] = R[j];
      j++;
      k++;
      update(); // Update visualization after each comparison
    }
}

void Application::mergeSort(int low, int high) {
  if (low < high)
  {
    // Find the middle point
    int mid = low + (high - low) / 2;

    // Sort first and second halves
    mergeSort(low, mid);
    mergeSort(mid + 1, high);

    // Merge the sorted halves
    merge(low, mid, high);
  }
}

void Application::mergeSortCall()
{
  mergeSort(0, arraySize -1);
}
