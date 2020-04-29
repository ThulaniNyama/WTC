//
//  IntraAPI.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

import UIKit

struct BearerToken: Decodable {
    var access_token: String
}

struct Sections {
    let sectionName : String
    var isExpanded : Bool
    var arr: [Projects]
    let finalMark : String?
    let validated : Bool?
}

class IntraAPI {
    
    let myUid = "7367cc662c43bf0a65368c8c2ecdc20b39e50cbafff46d6ac75e39a94143f154"
    let mySecret = "89c60b09b829195e271c0789cb46a62f5757e878769546a54f6e200f708feab5"
    
    var token : BearerToken?
    var user : Person?
    var group : [Coalition]?
    
    var poolC = [Projects]()
    var projectsSection = [Projects]()
    var poolsArray = [Sections]()

    func getBearerToken() {
  
        var request = URLRequest(url: URL(string: "https://api.intra.42.fr/oauth/token")!)
        
        request.httpMethod = "POST"
        request.addValue("application/json", forHTTPHeaderField: "Content-Type")
        request.httpBody = try? JSONSerialization.data(withJSONObject: ["grant_type": "client_credentials", "client_id" : myUid, "client_secret" : mySecret], options: .prettyPrinted)
        
        URLSession.shared.dataTask(with: request) {(data, response, error) in
            do {
                self.token = try JSONDecoder().decode(BearerToken.self, from: data!)
                print(self.token!.access_token)
            } catch {
                print(error)
            }
        }.resume()
    }
    
    
    func makeUserRequest(login : String, completionHandler: @escaping (Person?, Error?) -> Void) -> (result : Bool, message : String?) {
        
        guard let newToken = self.token else {
            print("token error")
            return (false, "Connection problems")
        }
        guard let url = URL(string: "https://api.intra.42.fr/v2/users/" + login) else { return (false, "Login not found") }
        var request = URLRequest(url: url)
        
        request.httpMethod = "GET"
        request.addValue("Bearer \(newToken.access_token)", forHTTPHeaderField: "Authorization")
        
        URLSession.shared.dataTask(with: request) { (data, response, error) in
            do {
                let jsonResponse = try JSONDecoder().decode(Person.self, from: data!)
                completionHandler(jsonResponse, nil)
              } catch {
                completionHandler(nil, error)
            }
        }.resume()
        return (true, nil)
    }
    
    
    func makeCoalitionRequest(complitionHandler: @escaping ([Coalition]?, Error?) -> Void) {
        
        guard let newToken = self.token else {
            print("token is not ready yet")
            return
        }
        
        guard let idNbr = user?.id else { return }
       
        print(URL(string: "https://api.intra.42.fr/v2/users/" + String(describing: idNbr) + "/coalitions")!)
        var request = URLRequest(url: URL(string: "https://api.intra.42.fr/v2/users/" + String(describing: idNbr) + "/coalitions")!)
        request.httpMethod = "GET"
        request.addValue("Bearer \(newToken.access_token)", forHTTPHeaderField: "Authorization")
        
        URLSession.shared.dataTask(with: request) { (data, response, error) in
            do {
                let jsonResponse = try JSONDecoder().decode([Coalition].self, from: data!)
                complitionHandler(jsonResponse, nil)
            } catch {
                complitionHandler(nil, error)
            }
            }.resume()
    }
    
    
    func saveProjects () {
        if let projectsArr = user?.projects_users {
            
            for key in projectsArr {
                guard let slug = key.project?.slug else { continue }
                guard let name = key.project?.name else { continue }
                
                if (slug.hasPrefix("piscine-c-") && key.project?.parent_id == nil) {
                    poolC.append(key)
                }
                
                else if (name.contains("Piscine") && !name.contains("Reloaded")) {
                    if let id = key.project?.id {
                        var newSection = [Projects]()
                        
                        for key in projectsArr {
                            if key.project?.parent_id == id {
                                newSection.append(key)
                            }
                        }
                        if let mark : Int = key.final_mark {
                            poolsArray.append(Sections(sectionName: name, isExpanded: false, arr: newSection, finalMark: String(mark), validated: key.validated!))
                        } else {
                            poolsArray.append(Sections(sectionName: name, isExpanded: false, arr: newSection, finalMark: nil, validated: nil))
                        }
                    }
                }
                
                else if (key.project?.parent_id == nil && !slug.hasPrefix("piscine-c-")) {
                    projectsSection.append(key)
                }
            }
            
            if !Sections(sectionName: "Pool C", isExpanded: false, arr: poolC, finalMark: nil, validated: nil).arr.isEmpty {
                poolsArray.append(Sections(sectionName: "Pool C", isExpanded: false, arr: poolC, finalMark: nil, validated: nil))
            }
            
            if !Sections(sectionName: "Projects", isExpanded: true, arr: projectsSection, finalMark: nil, validated: nil).arr.isEmpty {
                poolsArray.append(Sections(sectionName: "Projects", isExpanded: true, arr: projectsSection, finalMark: nil, validated: nil))
            }
        }
    }
}






