//
//  ProfileViewController.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit

class ProfileViewController: UIViewController {

    
   // @IBOutlet weak var avatarBackground: UIView!
    @IBOutlet weak var coalitionView: UIImageView!
   // @IBOutlet weak var avatarView: UIImageView!
    
    @IBOutlet weak var avatar: UIImageView!
    @IBOutlet weak var levelProgress: UIProgressView!
    @IBOutlet weak var levelLabel: UILabel!
    
    @IBOutlet weak var nameView: UIView!
 
    @IBOutlet weak var firstNameLabel: UILabel!
    @IBOutlet weak var lastNameLabel: UILabel!
    
    //@IBOutlet weak var contactsView: UIView!
    @IBOutlet weak var phoneLabel: UILabel!
    @IBOutlet weak var walletLabel: UILabel!
    @IBOutlet weak var corPointsLabel: UILabel!
    
    @IBOutlet weak var locationView: UIView!
    @IBOutlet weak var cityLabel: UILabel!
    @IBOutlet weak var availabilityLabel: UILabel!
   
    override func viewDidLoad() {
        super.viewDidLoad()
               
        let tabBar = tabBarController as! TabBarController
        
        //avatarBackground.layer.cornerRadius = 15
        nameView.layer.cornerRadius = 15
        //contactsView.layer.cornerRadius = 15
        locationView.layer.cornerRadius = 15
        
        levelProgress.layer.cornerRadius = 8
        levelProgress.clipsToBounds = true
        levelProgress.layer.sublayers![1].cornerRadius = 8
        levelProgress.subviews[1].clipsToBounds = true

        avatar.layer.borderWidth = 1
        avatar.layer.masksToBounds = false
        avatar.layer.borderColor = UIColor.lightGray.cgColor
        avatar.layer.cornerRadius = 15
        avatar.clipsToBounds = true

        
        //Avatar
        
        let getImgFromUrl = URLSession(configuration: .default).dataTask(with: URL(string: tabBar.api?.user?.image_url ?? "")!) {(data, response, error) in
            if let error = error {
                print("Error Occurred: \(error)")
            } else {
                if (response as? HTTPURLResponse) != nil {
                    DispatchQueue.main.async {
                        self.avatar.image = UIImage(data : data!)
                    }
                }
            }
        }
        getImgFromUrl.resume()
        
        //Level Progress
        
        if let cursus = tabBar.api?.user?.cursus_users {
            levelProgress.progress = cursus[0].level!.truncatingRemainder(dividingBy: 1)
            levelLabel.text = "level " + String(cursus[0].level!) + "%"
            levelProgress.layer.borderWidth = 0.5
            levelProgress.layer.borderColor =  UIColor.lightGray.cgColor
        }
        
        //Login View
        
        firstNameLabel.text = tabBar.api?.user?.first_name
        lastNameLabel.text = tabBar.api?.user?.last_name
        
        //Contacts View
        
        phoneLabel.text = "📞 \(tabBar.api?.user?.phone ?? "-")"
        walletLabel.text =  "Wallet: \(tabBar.api?.user?.wallet ?? 0)"
        corPointsLabel.text = "Correction Points: \(tabBar.api?.user?.correction_point ?? 0)"
        
        //Location View
        
        if let campus = tabBar.api?.user?.campus {
            cityLabel.text = !campus.isEmpty ? "\(campus[0].name ?? "-")" : ""
        }
        availabilityLabel.text = "Unavailable"
        availabilityLabel.textColor =  UIColor.white
    }

}

