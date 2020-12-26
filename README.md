### SYMBOLIC EXPRESSION EXPANDER

## Description

Have you ever had the need to expand a symbolic expression without using a GUI? (I'm looking at you MatLab)
Have you ever needed to do it just in your terminal with a rough and possibly not that good implementation? Well, look no more, you've reached the thing you're looking for.

Introducing a command-line approach to your needs, possibly not optimised, and with a metric f-ton of bugs (to be determined).

All you need to do is input a JSON file with your un-expanded expressions and et voilà, this approach will return the expanded version of those (so called) expressions!
And that's it.

## Compiling

On the project root folder path

Under Windows: (todo; verify this)
```bash
mkdir build
cd build
cmake ..
main.exe -f config.json
```

Under macOS/Linux distros:

````bash
mkdir build
cmake ..
make
./main -f config.json
```

## Usage and considerations

The main intend of this project is to expand a function of _n_ symbolic variables.
All letters (or combinations of) in the roman alphabet are accepted as symbolic variables, symbols are sadly, not accepted as variable names.

To have a multiplication, a `*` has to be used explicitely, `^` is used strictly for a boolean (or bitwise) exclusive or. Power is represented by `**`.

If you want to expand <img src="http://latex.codecogs.com/svg.latex?\left%20(%20x^{2}%20\right%20)\left%20(%20y^{4}&plus;%20x^{78}%20\right%20)(x&plus;y)^{3}(x-4)/(y&plus;8)" title="http://latex.codecogs.com/svg.latex?\left%20(%20x^{2}%20\right%20)\left%20(%20y^{4}+%20x^{78}%20\right%20)(x+y)^{3}(x-4)/(y+8)" />
you'd have to write in the JSON (more on that below) 

````bash
(x**2)*(y*44 + x**78)*((x+y)**3)*(x-4)/(y+8)
```

## Contributing

We encourage you to contribute to our project, it's quite simple and should't need taht much work, but do you happen to have an idea and could use this as a foundation? Go ahead and do it! You could help this little project be useful to people outside our team, and that be great :grin:, so go ahead and check out the [Contributing thingy](CONTRIBUTING.md)
