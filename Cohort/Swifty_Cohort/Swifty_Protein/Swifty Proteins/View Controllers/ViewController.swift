//
//  ViewController.swift
//  Swifty Proteins
//
//  Created by Sbusiso Xaba on 2019/11/22.
//  Copyright © 2019 sbxaba. All rights reserved.
//

import UIKit
import LocalAuthentication

class ViewController: UIViewController {

    var ListOfLigands : [String] = []
    @IBOutlet weak var LoginButton: UIButton!
    var context : LAContext!
    
    @IBAction func Login(_ sender: UIButton) {
        self.context.evaluatePolicy(LAPolicy.deviceOwnerAuthenticationWithBiometrics, localizedReason: "TouchID is required to authenticate Swifty Proteins")
        {
            (wasSuccessful, error) in
            if wasSuccessful
            {
                DispatchQueue.main.async {
                    self.performSegue(withIdentifier: "GoToListView", sender: self)
                }
            }
            else
            {
                print("Wrong Finger!")
            }
        }
    }
    
    func getLigands( with success : @escaping (Data) -> (Void), with erroring : @escaping (Error) -> (Void))
    {
        let url = URL(string:"https://projects.intra.42.fr/uploads/document/document/312/ligands.txt")!
        let task = URLSession.shared.dataTask(with:url) { (data, response, error) in
            if error != nil {
                DispatchQueue.main.async {
                    erroring(error!)
                }
            }
            else {
                DispatchQueue.main.async {
                    success(data!)
                }
            }
        }
        task.resume()
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "GoToListView" {
            if let nextViewController = segue.destination as? ProteinListViewController {
                    nextViewController.ListOfLigands = self.ListOfLigands
            }
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.context = LAContext()
        
        //check if phone is compatible with the finger ish
        if context.canEvaluatePolicy(.deviceOwnerAuthenticationWithBiometrics, error: nil)
        {
            self.LoginButton.isHidden = false
        }
        else
        {
            self.LoginButton.isHidden = true
        }
        
        self.getLigands(with: { (data) -> (Void) in
            if let ligand = String(data: data, encoding: .utf8) {
                for i in ligand.split(separator: "\n") {
                    self.ListOfLigands.append(String(i))
                }
            }
        }, with: { (error) -> (Void) in
            print(error.localizedDescription)
        })
    }
}

