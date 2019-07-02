/* 
#Copyright (C) <June, 2019>  <Paribartan Dhakal>

#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU Affero General Public License as
#published by the Free Software Foundation, either version 3 of the
#License, or (at your option) any later version.


#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU Affero General Public License for more details.
*/


#include <iostream>
#include <ros/ros.h>
#include "../include/tree.h"

using namespace std;

int main(int argc, char* argv[])
{
    string param;
    ros::init(argc, argv, "tree_node");
    ros::NodeHandle nh("~");
    nh.getParam("param", param);
    ROS_INFO("Got Parameter: %s", param.c_str());
    const char* fileName = param.c_str();
    cout<<fileName<<endl;
    
    tree::BT bt;

    tree::Node* root = bt.buildBT(fileName);

    bt.execute(root, 1000);

    return 0;
}
