//
//  ProjectsViewController.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit

class ProjectsViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    @IBOutlet weak var tableView: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.dataSource = self
        tableView.delegate = self
    }
    

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
    
        let tabBar = tabBarController as! TabBarController
        
        return !((tabBar.api?.poolsArray) != nil) || !(tabBar.api?.poolsArray[section].isExpanded)! ? 0 : (tabBar.api?.poolsArray[section].arr.count)!
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell  {
        let tabBar = tabBarController as! TabBarController
        let cell = tableView.dequeueReusableCell(withIdentifier: "cellid", for: indexPath) as! ProjectsCell
        guard let projects = tabBar.api?.poolsArray else { return cell }
        cell.initCell(key: projects[indexPath.section].arr[indexPath.row])
        return cell
    }

    func numberOfSections(in tableView: UITableView) -> Int {
        let tabBar = tabBarController as! TabBarController
        guard let arr = tabBar.api?.poolsArray else { return 0 }
        return arr.count
    }
    
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        let tabBar = tabBarController as! TabBarController
        let button = UIButton(type: .system)
        
        if let projects = tabBar.api?.poolsArray {
            let text = projects[section].sectionName
            button.setTitle(text, for: .normal)
            if let mark = projects[section].finalMark {
                projects[section].validated! ? button.setTitle("✅  \(text)  \(mark) %", for: .normal) : button.setTitle("❌  \(text)  \(mark) %", for: .normal)
            }
        }
        button.setTitleColor(.white, for: .normal)
        button.setTitleColor(.gray, for: .selected)
        button.backgroundColor = UIColor.darkText
        button.layer.borderWidth = 1
        button.layer.borderColor = UIColor.lightGray.cgColor
        button.titleLabel?.font = UIFont.boldSystemFont(ofSize: 14)
        button.tag = section
        return button
        
    }
    
}
