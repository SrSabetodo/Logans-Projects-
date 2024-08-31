#include "StringBag.h"

stringBag_t StringBag::getBag()
{
  return bagVec;
}

void StringBag::add(const std::string &addMe)
{
  bagVec.insert(std::upper_bound(bagVec.begin(), bagVec.end(), addMe), addMe);
}

void StringBag::remove(const std::string &removeMe)
{
  bagVec.erase(std::lower_bound(bagVec.begin(), bagVec.end(), removeMe));
}

int StringBag::getCount(const std::string countof)
{
  // get first occurance of element in vector
  iterator_t it = std::lower_bound(bagVec.begin(), bagVec.end(), countof);

  int count = 0;

  // since they will all be next to each other, we only need to look
  // while it == countof
  for (; *it == countof; it++)
  {
    count++;
  }

  return count;
}

int StringBag::getSize()
{
  return bagVec.size();
}

std::ostream &operator<<(std::ostream &os, StringBag &bag)
{
  os << "StringBag{";

  int counter = 0;

  for (; counter != bag.getSize(); counter++)
  {
    if (counter == 0)
    {
      os << bag.getBag()[counter] << ":" <<
        bag.getCount(bag.getBag()[counter]) << ", ";
    }
    else if (counter > 0 && bag.getBag()[counter - 1] != bag.getBag()[counter])
    {
      os << bag.getBag()[counter] << ":" <<
        bag.getCount(bag.getBag()[counter]) << ", ";
    }
    else
    {
      continue;
    }
  }

  os << "}";

  return os;
}

std::string StringBag::getRandomString()
{
  // std::cout << *this << std::endl;
  if (bagVec.size() == 0)
  {
    return ".";
  }
  else
  {
    return getBag()[rand() % bagVec.size()]; // 1 line wonder
  }
}