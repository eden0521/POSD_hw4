# Pattern Oriented Software Design
#### Fall, 2018

#### Homework 4

# Purpose of the homework:

  Implement `name()` and `find()` method.

  The `find()` method is just like `find` command in linux.
  
# Requirements:
 1. Implement `name()` and `find()` method for File, Folder, Node class.

        std::string name()
        {
              return nodeName
        }
        std::string find(std::string nodeName)
        {
              //implementation
        }

      **Note**  
      `File.find(std::string nodeName)` should return the file name if the file was found.

            ASSERT.EQ("a.out",a_out->find("a.out"));

 2. The basic unit tests is given name "ut_fs.h" in the repository, you have to make the tests pass.
 
 3. **There is a situation you should be known. The fileSystem can have the same file/folder name in the different folder. Your answer should be all the paths divided by '\n'. Just like linux find multipath.**

      *Example: `a.out` in different folders*

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; *test_data/`a.out`*

    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*test_data/folder/`a.out`*

    And your answer of  `test_data.find('a.out')` should be:

        ./a.out\n./folder/a.out

    And the assertion should be:

        ASSERT.EQ("./a.out\n./folder/a.out",test_data->find("a.out"));

      Note

      The `find()` result is same as using the find command in test_data.

 4. Write the corresponding makefile to generate executable file which named **`hw4`** in bin folder.