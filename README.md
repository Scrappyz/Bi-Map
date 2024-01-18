## Bi-Map
A bi-directional map data structure in C++.

## Usage
```
int main(int argc, char** argv)
{
    BiMap<std::string, int> b = {{"one", 1}, {"two", 2}, {"three", 3}};

    std::cout << "one = " << b.at("one") << std::endl;
    std::cout << "1 = " << b.atInverse(1) << std::endl;
    std::cout << std::endl;
    std::cout << "two = " << b.at("two") << std::endl;
    std::cout << "2 = " << b.atInverse(2) << std::endl;
    std::cout << std::endl;
    std::cout << "three = " << b.at("three") << std::endl;
    std::cout << "3 = " << b.atInverse(3) << std::endl;

    return 0;
}
```

### Output
```
one = 1
1 = one

two = 2
2 = two

three = 3
3 = three
```