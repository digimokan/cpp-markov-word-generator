# cpp-markov-word-generator

Linux/UNIX command-line Markov Model word generator, written in C++.

[![Release](https://img.shields.io/github/release/digimokan/cpp-markov-word-generator.svg?label=release)](https://github.com/digimokan/cpp-markov-word-generator/releases/latest "Latest Release Notes")
[![License](https://img.shields.io/badge/license-MIT-blue.svg?label=license)](LICENSE.txt "Project License")
[![Build Status](https://img.shields.io/travis/com/digimokan/cpp-markov-word-generator/master.svg?label=linux+build)](https://travis-ci.com/digimokan/cpp-markov-word-generator "Build And Test Results From Master Branch")

## Table Of Contents

* [Motivation](#motivation)
* [Features](#features)
* [Requirements](#requirements)
* [Quick Start](#quick-start)
* [Full Usage / Options](#full-usage--options)
* [Examples](#examples)
* [Design](#design)
* [Source Code Layout](#source-code-layout)
* [Contributing](#contributing)

## Motivation

Use machine learning / deep learning to generate words using a Markov Model.
Train the model with data sets of words.

## Features

* Efficient, modern C++ 17.
* Variable model order (number of hidden Markov models).

## Requirements

* A Linux/UNIX system
* C++ 17
* Boost (version 1.66.0 or higher)
* CMake
* Git

## Quick Start

1. Clone project into a local project directory:

   ```shell
   $ git clone https://github.com/digimokan/cpp-markov-word-generator.git
   ```

2. Change to the local project directory:

   ```shell
   $ cd cpp-markov-word-generator
   ```

3. Build the program:

   ```shell
   $ ./third_party/smart-build/src/smart-build.sh --build-type-release
   ```

4. Run the program:

   ```shell
   $ ./markov-word-gen
   ```

## Full Usage / Options

```
<cut and paste help menu here>
```

## Examples

* Run with some option:

   ```shell
   $ ./markov-word-gen -d
   ```

* Run with some other option:

   ```shell
   $ ./markov-word-gen -rt
   ```

## Design

A paragraph or two about architecture.

<img src="readme_assets/design_diagram.svg" width="100%" height="400" alt="Design Diagram">

## Source Code Layout

```
├─┬ cpp-markov-word-generator/
│ │
│ ├─┬ src/
│ │ ├─┬ somea/
│ │ │ ├── Hello.cpp
│ │ │ └── Hello.hpp
│ │ ├─┬ someb/
│ │ │ ├── Goodbye.cpp
│ │ │ └── Goodbye.hpp
│ │ └── main.cpp
│ │
│ ├─┬ tests/
│ │ ├─┬ unit_tests/
│ │ │ └── Goodbye_test.cpp
│ │ └── doctest_testharness.cpp
│ │
│ ├─┬ third_party/
│ │ └─┬ doctest/
│ │   └── doctest.h
│ │
│ ├── .project_config
│ ├── .vimrc
│ ├── smart-build.sh
│ └── CMakeLists.txt
```

## Contributing

* Feel free to report a bug or propose a feature by opening a new
  [Issue](https://github.com/digimokan/cpp-markov-word-generator/issues).
* Follow the project's [Contributing](CONTRIBUTING.md) guidelines.
* Respect the project's [Code Of Conduct](CODE_OF_CONDUCT.md).

