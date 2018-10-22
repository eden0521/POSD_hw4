#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"

/*TEST (, FileSearchItsSelf)
{
  Node * a_out = new File("./test_data/folder/a.out");
  ASSERT_EQ("a.out",a_out->find("a.out"));
}
TEST (, FileSearchNotItsSelf)
{
  Node * a_out = new File("./test_data/folder/a.out");
  ASSERT_EQ("",a_out->find("b.out"));
}
TEST (, FolderSearchItsSelf)
{
  Node * folder = new Folder("./test_data/folder");
  ASSERT_EQ("",folder->find("folder"));
}
TEST (, FolderSearchNotItsSelf)
{
  Node * folder = new Folder("./test_data/folder");
  ASSERT_EQ("",folder->find("test_data"));
}

TEST (, SearchFileInFolder)
{
  Node * folder = new Folder("./test_data/folder");
  Node * a_out = new File("./test_data/folder/a.out");
  folder->add(a_out);
  ASSERT_EQ("./a.out",folder->find("a.out"));
}

TEST (, SearchFolderInFolder)
{
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  test_data->add(folder);
  ASSERT_EQ("./folder",test_data->find("folder"));
}*/

TEST (, SearchFileInMoreFolder)
{
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  Node * a_out = new File("./test_data/folder/a.out");
  //Node * b_out = new File("./test_data/a.out");
  //test_data->add(b_out);
  folder->add(a_out);
  test_data->add(folder);
  ASSERT_EQ("./folder/a.out",test_data->find("a.out"));
}

TEST (, SearchMoreFileInMoreFolder)
{
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  Node * folder2 = new Folder("./test_data/folder/folder2");
  Node * folder3 = new Folder("./test_data/folder/folder2/folder3");
  Node * a_out = new File("./test_data/a.out");
  Node * a_out2 = new File("./test_data/folder/a.out");
  Node * a_out3 = new File("./test_data/folder/folder2/a.out");
  Node * a_out4 = new File("./test_data/folder/folder2/folder3/a.out");
  folder3->add(a_out4);
  folder2->add(folder3);
  folder2->add(a_out3);
  folder->add(a_out2);
  folder->add(folder2);
  test_data->add(folder);
  test_data->add(a_out);
  ASSERT_EQ("./a.out\n./folder/a.out\n./folder/folder2/a.out\n./folder/folder2/folder3/a.out",test_data->find("a.out"));
}



#endif
