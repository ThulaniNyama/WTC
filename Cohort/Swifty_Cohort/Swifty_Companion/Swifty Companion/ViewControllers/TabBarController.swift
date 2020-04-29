//
//  TabBarController.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit

class TabBarController: UITabBarController {
    
    var api : IntraAPI?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        if let mail = api?.user?.email{
            self.title = mail
        }
    }

    override func viewWillAppear(_ animated: Bool) {
             super.viewWillAppear(true)
     
            // Show the Navigation Bar
           self.navigationController?.setNavigationBarHidden(false, animated: true)
      }
    
    
    override func viewWillDisappear(_ animated: Bool) {
         super.viewWillDisappear(true)
        
        // Clear loaded data
        self.api?.poolC.removeAll()
        self.api?.projectsSection.removeAll()
        self.api?.poolsArray.removeAll()
        self.api?.user?.projects_users?.removeAll()
    }
}
