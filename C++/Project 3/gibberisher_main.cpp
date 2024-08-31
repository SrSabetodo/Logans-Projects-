#include "./src/Gibberisher.h"
#include <time.h>
#include <string.h>

int main()
{
  srand(time(NULL));

  Gibberisher gib(5);

  std::vector<std::string> inputFiles = {
    // "quixote.txt",
    "marx.txt",
    // "war_and_peace.txt",
    // "romeno_n_juliet.txt",
    // "moby_dick.txt",
    // "hp1.txt",
    // "hp2.txt",
    // "hp3.txt",
    // "hp4.txt",
    // "hp5.txt",
    // "hp6.txt",
    // "hp7.txt",
  };

  gib.train(gib.getTrainingDataVector(inputFiles));

  std::cout << "===============================================\n";
  std::cout << "\tNum samples processed: " << gib.getNumSamplesProcessed() << "\n";
  std::cout << "===============================================\n";

  for (int i = 0 ; i < 10 ; i++)
  {
    std::string word = gib.generate();
    word[0] = toupper(word[0]);
    word += " ";
    std::cout << word;
  }

  puts("");

  return 0;
}
