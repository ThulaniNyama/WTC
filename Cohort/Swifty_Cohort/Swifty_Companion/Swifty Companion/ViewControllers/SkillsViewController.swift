//
//  SkillsViewController.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit

class SkillsViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    @IBOutlet weak var tableView: UITableView!
   
    @IBOutlet weak var spiderView: DDSpiderChartView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.delegate = self
        tableView.dataSource = self
        spiderView.isHidden = true
      
        let tabBar = tabBarController as! TabBarController
        
        if !(tabBar.api?.user?.cursus_users?.isEmpty)! {
            if !(tabBar.api?.user?.cursus_users![0].skills?.isEmpty)! {
                spiderView.isHidden = false
            }
            var values = [Float]()
            var names = [String]()
            spiderView.color = UIColor(red: 170/255, green: 207/255, blue: 226/255, alpha: 0.8)
            for key in (tabBar.api?.user?.cursus_users![0].skills)! {
                names.append(key.name)
            }
            names.sort()
            
            for i in names {
                spiderView.axes.append(i)
                
                for j in (tabBar.api?.user?.cursus_users![0].skills)! {
                    if j.name == i {
                        values.append(j.level/17)
                    }
                }
                
            }
            spiderView.addDataSet(values: values, color: UIColor(red: 40/255, green: 74/255, blue: 204/255, alpha: 1))
        }
        return
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        let tabBar = tabBarController as! TabBarController

        if !(tabBar.api?.user?.cursus_users?.isEmpty)! {
            return (tabBar.api?.user?.cursus_users![0].skills!.count)!
        }
        return 0
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
    
        let tabBar = tabBarController as! TabBarController
        let cell = tableView.dequeueReusableCell(withIdentifier: "skillCell", for: indexPath) as! SkillsCell
    
        if !(tabBar.api?.user?.cursus_users?.isEmpty)! {
            cell.initCell(name: (tabBar.api?.user?.cursus_users![0].skills![indexPath.row].name)! , value: (tabBar.api?.user?.cursus_users![0].skills![indexPath.row].level)!)
        }
        return cell
    }
 
}
    

