//
//  File.swift
//  Swifty Companion
//
//  Created by Thulani Nyama on 2019/10/23.
//  Copyright © 2019 tnyama. All rights reserved.
//

struct Coalition: Decodable {
    let name : String?
}

struct ProjectStruct: Codable {
    let id : Int?
    let name : String?
    let parent_id : Int?
    let slug : String?
}

struct Projects: Codable {
    
    let final_mark: Int?
    let status: String?
    let validated: Bool?
    let project : ProjectStruct?
    
    enum CodingKeys: String, CodingKey {
        case final_mark
        case status
        case validated = "validated?"
        case project
    }
}

struct Skills: Decodable {
    let name : String
    let level : Float
}

struct Cursus: Decodable {
    let grade: String?
    let level: Float?
    let has_coalition: Bool
    let skills: [Skills]?
}

struct City: Decodable {
    let name: String?
}

struct Person: Decodable {

    var id: Int?
    var login : String?
    var error: String?
    var message: String?
    
    var image_url : String?
    
    var first_name : String?
    var last_name : String?
    
    var phone : String?
    var email : String?
    var wallet : Int?
    var correction_point : Int?
    
    var projects_users: [Projects]?
    var cursus_users: [Cursus]?
    var campus: [City]?
}
