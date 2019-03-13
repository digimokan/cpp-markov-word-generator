/*******************************************************************************
module:   ProgramOpts
author:   digimokan
date:     12 MAR 2019
purpose:  process program options and act on them (make objs, take actions, etc)
*******************************************************************************/

#ifndef PROGRAM_OPTS_HPP
#define PROGRAM_OPTS_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <boost/program_options.hpp>
#include <memory>
#include <string>

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class WordBatchGenerator;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class ProgramOpts {

public:

  // constructors
  ProgramOpts () = delete;
  ProgramOpts (int argc, char* argv[]);

  // destructor
  ~ProgramOpts () = default;

  // operators
  ProgramOpts (const ProgramOpts& in) = default;
  ProgramOpts& operator= (const ProgramOpts& rh) = delete;
  ProgramOpts (ProgramOpts&& in) = default;
  ProgramOpts& operator= (ProgramOpts&& rh) = delete;

  // specialized methods
  std::shared_ptr<WordBatchGenerator> create_word_generator ();

private:

  // helper methods
  void define_opts ();
  void parse_opts ();
  void check_opts ();
  std::shared_ptr<WordBatchGenerator> make_word_gen ();
  void opt_help ();
  void opt_missing (const std::string& optname);
  void opt_order ();
  void opt_min_word_length ();
  void opt_max_word_length ();
  void opt_words_text_file ();
  void opt_num_words_to_gen ();

  // fields
  int argc;
  char** argv;
  boost::program_options::options_description opts;
  boost::program_options::positional_options_description posopts;
  boost::program_options::command_line_parser parser;
  boost::program_options::variables_map optsmap;
  std::size_t order;
  std::size_t min_word_length;
  std::size_t max_word_length;
  std::string words_text_file;
  std::size_t num_words_to_gen;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // PROGRAM_OPTS_HPP

