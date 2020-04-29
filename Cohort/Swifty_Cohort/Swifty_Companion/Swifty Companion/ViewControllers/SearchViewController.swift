//
//  ViewController.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit

class SearchViewController: UIViewController, UISearchBarDelegate {

    let api = IntraAPI()
    
    @IBOutlet weak var searchBar: UISearchBar!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        api.getBearerToken()
        searchBar.delegate = self

        searchBar.layer.cornerRadius = 7
        searchBar.clipsToBounds = true
   
       }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        searchBar.resignFirstResponder()
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        guard let tabBarViewController = segue.destination as? TabBarController else { return }
        tabBarViewController.api = api
    }
    
    
    
    private func getUserInfo(_ userData: Person, _ searchBar: UISearchBar) {
        if userData.login == (searchBar.text?.lowercased())! {
            self.api.user = userData
            self.api.makeCoalitionRequest() { coalition, error in
                DispatchQueue.main.async {
                    if let userCoalition = coalition {
                        self.api.group = userCoalition
                        self.api.saveProjects()
                        self.performSegue(withIdentifier: "goToResult", sender: self)
                    }
                }
            }
        } else {
            let alertController = UIAlertController(title: "Error", message: "Login not found", preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "Ok", style: .default , handler: nil))
            self.present(alertController, animated: true, completion: nil)
        }
    }
    
    func searchBarSearchButtonClicked(_ searchBar: UISearchBar) {
        searchBar.resignFirstResponder()
        
        let answer = (api.makeUserRequest(login: (searchBar.text?.lowercased())!, completionHandler: { user, error in
            DispatchQueue.main.async {
                if let userData = user {
                    self.getUserInfo(userData, searchBar)
                }
            }
        }))
        if !answer.result {
            api.getBearerToken()
            
            let alertController = UIAlertController(title: "Error", message: answer.message, preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "Ok", style: .default , handler: nil))
            self.present(alertController, animated: true, completion: nil)
        }
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(true)
        
        // Hide the Navigation Bar
        self.navigationController?.setNavigationBarHidden(true, animated: true)
    }
    
}





